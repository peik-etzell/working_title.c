#include "viewplane.h"

vec raycast(vec ray, plane plane) {
    return mul_vs(ray, plane.d / dot(ray, plane.normal));
}
