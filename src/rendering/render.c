#include "render.h"

#include <assert.h>
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../linalg/line.h"
#include "../linalg/plane.h"
#include "../linalg/triangle.h"
#include "../linalg/vec.h"
#include "../utils/macros.h"
#include "../utils/term.h"
#include "pixel.h"
#include "viewplane.h"

const float FOV = 70;
static float vp_dist(termsz sz) {
    return (float)sz.w * 0.5f / tanf(FOV * 0.5f * (float)M_PI / 360);
}

struct {
    float *lum;
    float *z;
    size_t size;
} FRAMEBUF = {0};

void reset_framebuf(termsz sz) {
    size_t required = sz.h * sz.w;
    if (required > FRAMEBUF.size) {
        FRAMEBUF.lum = realloc(FRAMEBUF.lum, required * sizeof(float));
        FRAMEBUF.z = realloc(FRAMEBUF.z, required * sizeof(float));
        FRAMEBUF.size = required;
    }
    // Reset framebuffer contents
    for (size_t i = 0; i < required; ++i) {
        FRAMEBUF.lum[i] = 0;
        FRAMEBUF.z[i] = FLT_MAX;
    }
}

void render(tribuf T) {
    termsz term = get_termsize();
    float viewplane_dist = vp_dist(term);
    reset_framebuf(term);

    pixelf screen_offset = {(float)term.w * 0.5f, (float)term.h * 0.5f};

    for (size_t t = 0; t < T.n; ++t) {
        vec av, bv, cv;
        av = *T.data[t].a;
        bv = *T.data[t].b;
        cv = *T.data[t].c;

        plane tri_plane = create_plane(av, bv, cv);

        pixelf a, b, c;
        a = into_viewplane(av, viewplane_dist, screen_offset);
        b = into_viewplane(bv, viewplane_dist, screen_offset);
        c = into_viewplane(cv, viewplane_dist, screen_offset);

        line ab, bc, ca;
        ab = line_from_points(a, b);
        bc = line_from_points(b, c);
        ca = line_from_points(c, a);

        size_t min_x, min_y, max_x, max_y;
        min_x = (size_t)boundf(min3(a.x, b.x, c.x), 0, (float)term.w);
        min_y = (size_t)boundf(min3(a.y, b.y, c.y), 0, (float)term.h);
        max_x = (size_t)boundf(ceilf(max3(a.x, b.x, c.x)), 0, (float)term.w);
        max_y = (size_t)boundf(ceilf(max3(a.y, b.y, c.y)), 0, (float)term.h);

        float sign_ab, sign_bc, sign_ca;
        vec ray;
        float sun_illumination =
            fmaxf(dot(tri_plane.normal, (vec){0, -1, 0}) * 0.1f, 0);
        for (size_t row = min_y; row < max_y; ++row) {
            for (size_t col = min_x; col < max_x; ++col) {
                pixelf p = {(float)col, (float)row};
                sign_ab = signed_distance(ab, p);
                sign_bc = signed_distance(bc, p);
                sign_ca = signed_distance(ca, p);
                // Pixel inside triangle?
                if (sign_ab > 0 && sign_bc > 0 && sign_ca > 0) {
                    ray = ray_from_viewplane(
                        row, col, viewplane_dist, screen_offset
                    );
                    vec p_on_tri = raycast(ray, tri_plane);
                    size_t fb_idx = row * term.w + col;
                    // Pixel foremost thus far? (and not behind camera)
                    if (p_on_tri.z < FRAMEBUF.z[fb_idx] && p_on_tri.z > 0) {
                        FRAMEBUF.z[fb_idx] = p_on_tri.z;
                        vec n_ray = normalized(ray);
                        float lum = -dot(n_ray, tri_plane.normal) * 0.9f;
                        if (lum > 0)
                            FRAMEBUF.lum[fb_idx] = lum + sun_illumination;
                    }
                }
            }
        }
    }

    clear_screen();
    int jumping = 0;
    for (size_t row = 0; row < term.h; ++row) {
        for (size_t col = 0; col < term.w; ++col) {
            float luminance = FRAMEBUF.lum[row * term.w + col];
            if (luminance == 0) {
                jumping = 1;
                continue;
            }
            if (jumping) {
                cursor_move(row, col);
                jumping = 0;
            }
            putchar(lum2char(luminance));
        }
    }
    cursor_home();
}
