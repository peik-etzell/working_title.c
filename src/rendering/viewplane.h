#ifndef RENDERING_VIEWPLANE_H
#define RENDERING_VIEWPLANE_H

#include "../linalg/plane.h"
#include "../linalg/vec.h"
#include "pixel.h"

// Monospace characters are CHAR_RATIO times taller than wide
static const float CHAR_RATIO = 3.f / 1;
// Reciprocal of CHAR_RATIO
static const float CHAR_RATIO_RECIP = 1.f / CHAR_RATIO;

/**
 * @brief Cast a ray from the origin to the plane in the direction of the ray.
 * @returns The intesection of ray and plane
 */
vec raycast(vec ray, plane plane);

static inline pixelf into_viewplane(vec p, float vp_dist, pixelf offset) {
    float scale = fabsf(vp_dist / p.z);
    return (pixelf){
        p.x * scale * CHAR_RATIO + offset.x, p.y * scale + offset.y};
}

/**
 * @brief Inverse operation of `into_viewplane()`
 */
static inline vec ray_from_viewplane(
    size_t row, size_t col, float vp_dist, pixelf offset
) {
    return (vec){
        ((float)col - offset.x) * CHAR_RATIO_RECIP, (float)row - offset.y,
        vp_dist};
}

#endif
