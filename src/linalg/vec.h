#ifndef LINALG_VEC_H
#define LINALG_VEC_H

#include <math.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} vec;

static const vec unitx = {1, 0, 0};
static const vec unity = {0, 1, 0};
static const vec unitz = {0, 0, 1};
static const vec zerovec = {0, 0, 0};

/**
 * Add two vectors
 * @returns (a + b)
 */
static inline vec add(vec a, vec b) {
    return (vec){a.x + b.x, a.y + b.y, a.z + b.z};
}
/**
 * Subtract b from a
 * @returns (a - b)
 */
static inline vec sub(vec a, vec b) {
    return (vec){a.x - b.x, a.y - b.y, a.z - b.z};
}
/**
 * Dot product
 * @returns a \cdot b
 */
static inline float dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}
/**
 * Cross product
 * @returns a x b
 */
static inline vec cross(vec a, vec b) {
    return (vec
    ){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x};
}
/**
 * Length
 * @returns |v|
 */
static inline float len(vec v) { return sqrtf(dot(v, v)); }
/**
 * Multiply
 * @returns v * s = s * v
 */
static inline vec mul_vs(vec v, float s) {
    return (vec){v.x * s, v.y * s, v.z * s};
}
/**
 * Divide
 * @returns v / s = v * (1./s)
 */
static inline vec divide(vec v, float s) { return mul_vs(v, 1.f / s); }
/**
 * Normalized
 */
static inline vec normalized(vec v) { return divide(v, len(v)); }

static inline void print_vec(vec v) {
    printf("[% .2E, % .2E, % .2E]\n", (double)v.x, (double)v.y, (double)v.z);
}

#endif
