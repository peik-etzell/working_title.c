#pragma once

#include <stdlib.h>

#include "../linalg/plane.h"
#include "../linalg/vec.h"
#include "pixel.h"

/**
 * @brief Cast a ray from the origin to the plane in the direction of the ray.
 * @returns The intesection of ray and plane
 */
vec raycast(vec ray, plane plane);

pixelf into_viewplane(vec p, float vp_dist, pixelf offset);

/**
 * @brief Inverse operation of `into_viewplane()`
 */
vec ray_from_viewplane(size_t row, size_t col, float vp_dist, pixelf offset);
