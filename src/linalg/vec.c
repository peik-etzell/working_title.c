#include "vec.h"

#include <math.h>
#include <stdio.h>

vec add(vec a, vec b) { return (vec){a.x + b.x, a.y + b.y, a.z + b.z}; }

vec sub(vec a, vec b) { return (vec){a.x - b.x, a.y - b.y, a.z - b.z}; }

float dot(vec a, vec b) { return (a.x * b.x + a.y * b.y + a.z * b.z); }

vec cross(vec a, vec b) {
    return (vec
    ){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

float len(vec v) { return sqrtf(dot(v, v)); }

vec mul_vs(vec v, float s) { return (vec){v.x * s, v.y * s, v.z * s}; }

vec divide(vec v, float s) { return mul_vs(v, 1.f / s); }

vec normalized(vec v) { return divide(v, len(v)); }

void print_vec(vec v) {
    printf("[% .2E, % .2E, % .2E]\n", (double)v.x, (double)v.y, (double)v.z);
}
