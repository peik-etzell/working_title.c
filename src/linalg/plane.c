#include "plane.h"

#include <assert.h>
#include <math.h>

#include "vec.h"

vec project(vec point, plane plane) {
    return sub(point, mul_vs(plane.normal, dot(plane.normal, point) - plane.d));
}
plane create_plane(vec a, vec b, vec c) {
    plane p;
    p.normal = normalized(cross(sub(b, a), sub(c, a)));
    assert(fabsf(len(p.normal) - 1) < 1e-6f);
    p.d = dot(p.normal, a);
    return p;
}
