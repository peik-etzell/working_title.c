#ifndef LINALG_MAT_H
#define LINALG_MAT_H

#include <stdio.h>

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

static inline mat identity() {
    mat m;
    m.a11 = m.a22 = m.a33 = 1;
    return m;
}
static inline float det(mat m) {
    return m.a11 * (m.a22 * m.a33 - m.a23 * m.a32) -
           m.a12 * (m.a21 * m.a33 - m.a23 * m.a31) +
           m.a13 * (m.a21 * m.a32 - m.a22 * m.a31);
}

static inline vec col1(mat m) { return (vec){m.a11, m.a21, m.a31}; }
static inline vec col2(mat m) { return (vec){m.a12, m.a22, m.a32}; }
static inline vec col3(mat m) { return (vec){m.a13, m.a23, m.a33}; }
static inline vec row1(mat m) { return (vec){m.a11, m.a12, m.a13}; }
static inline vec row2(mat m) { return (vec){m.a21, m.a22, m.a23}; }
static inline vec row3(mat m) { return (vec){m.a31, m.a32, m.a33}; }

static inline mat from_cols(vec c1, vec c2, vec c3) {
    return (mat){
        c1.x, c2.x, c3.x, c1.y, c2.y, c3.y, c1.z, c2.z, c3.z,
    };
}

static inline mat mul_ms(mat m, float s) {
    return (mat){
        m.a11 * s, m.a12 * s, m.a13 * s, m.a21 * s, m.a22 * s,
        m.a23 * s, m.a31 * s, m.a32 * s, m.a33 * s,
    };
}
static inline vec mul_mv(mat m, vec v) {
    return (vec){
        dot(row1(m), v),
        dot(row2(m), v),
        dot(row3(m), v),
    };
}
static mat mul_mm(mat a, mat b) {
    return from_cols(
        (vec
        ){dot(row1(a), col1(b)), dot(row2(a), col1(b)), dot(row3(a), col1(b))},
        (vec
        ){dot(row1(a), col2(b)), dot(row2(a), col2(b)), dot(row3(a), col2(b))},
        (vec
        ){dot(row1(a), col3(b)), dot(row2(a), col3(b)), dot(row3(a), col3(b))}
    );
}
static void print_mat(mat m) {
    printf(
        "[% 3f;% 3f; % 3f\n % 3f;% 3f; % 3f\n % 3f;% 3f; % 3f]", (double)m.a11,
        (double)m.a12, (double)m.a13, (double)m.a21, (double)m.a22,
        (double)m.a23, (double)m.a31, (double)m.a32, (double)m.a33
    );
}

#endif
