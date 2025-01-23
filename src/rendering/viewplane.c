#include "viewplane.h"

#include <math.h>
#include <stdlib.h>

#include "../linalg/plane.h"
#include "../linalg/vec.h"
#include "pixel.h"

// Monospace characters are CHAR_RATIO times taller than wide
static const float CHAR_RATIO = 2.5f / 1.f;
// Reciprocal of CHAR_RATIO
static const float CHAR_RATIO_RECIP = 1.f / CHAR_RATIO;

vec raycast(vec ray, plane plane) {
    return mul_vs(ray, plane.d / dot(ray, plane.normal));
}
pixelf into_viewplane(vec p, float vp_dist, pixelf offset) {
    float scale = fabsf(vp_dist / p.z);
    return (pixelf
    ){p.x * scale * CHAR_RATIO + offset.x, p.y * scale + offset.y};
}

vec ray_from_viewplane(size_t row, size_t col, float vp_dist, pixelf offset) {
    return (vec
    ){((float)col - offset.x) * CHAR_RATIO_RECIP, (float)row - offset.y, vp_dist
    };
}
