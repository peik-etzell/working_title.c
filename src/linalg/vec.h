#pragma once

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
vec add(vec a, vec b);
/**
 * Subtract b from a
 * @returns (a - b)
 */
vec sub(vec a, vec b);
/**
 * Dot product
 * @returns a \cdot b
 */
float dot(vec a, vec b);
/**
 * Cross product
 * @returns a x b
 */
vec cross(vec a, vec b);
/**
 * Length
 * @returns |v|
 */
float len(vec v);
/**
 * Multiply
 * @returns v * s = s * v
 */
vec mul_vs(vec v, float s);
/**
 * Divide
 * @returns v / s = v * (1./s)
 */
vec divide(vec v, float s);
/**
 * Normalized
 */
vec normalized(vec v);

void print_vec(vec v);
