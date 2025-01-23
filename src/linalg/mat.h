#pragma once

#include "vec.h"

typedef struct {
    float a11;
    float a12;
    float a13;
    float a21;
    float a22;
    float a23;
    float a31;
    float a32;
    float a33;
} mat;

mat from_euler(float rx, float ry, float rz);

mat identity();
float det(mat m);

vec col1(mat m);
vec col2(mat m);
vec col3(mat m);
vec row1(mat m);
vec row2(mat m);
vec row3(mat m);

mat from_cols(vec c1, vec c2, vec c3);

mat mul_ms(mat m, float s);
vec mul_mv(mat m, vec v);
mat mul_mm(mat a, mat b);
void print_mat(mat m);
