#include "mat.h"

#include <math.h>
#include <stdio.h>

#include "vec.h"

mat from_euler(float rx, float ry, float rz) {
    float sx = sinf(rx);
    float sy = sinf(ry);
    float sz = sinf(rz);
    float cx = cosf(rx);
    float cy = cosf(ry);
    float cz = cosf(rz);
    return (mat
    ){cy * cz,
      -cx * sz + sx * sy * cz,
      sx * sz + cx * sy * cz,
      cy * sz,
      cx * cz + sx * sy * sz,
      -sx * cz + cx * sy * sz,
      -sy,
      sx * cy,
      cx * cy};
}
mat mul_ms(mat m, float s) {
    return (mat){
        m.a11 * s, m.a12 * s, m.a13 * s, m.a21 * s, m.a22 * s,
        m.a23 * s, m.a31 * s, m.a32 * s, m.a33 * s,
    };
}

vec mul_mv(mat m, vec v) {
    return (vec){
        dot(row1(m), v),
        dot(row2(m), v),
        dot(row3(m), v),
    };
}

mat mul_mm(mat a, mat b) {
    return from_cols(
        (vec
        ){dot(row1(a), col1(b)), dot(row2(a), col1(b)), dot(row3(a), col1(b))},
        (vec
        ){dot(row1(a), col2(b)), dot(row2(a), col2(b)), dot(row3(a), col2(b))},
        (vec
        ){dot(row1(a), col3(b)), dot(row2(a), col3(b)), dot(row3(a), col3(b))}
    );
}

void print_mat(mat m) {
    printf(
        "[% 3f;% 3f; % 3f\n % 3f;% 3f; % 3f\n % 3f;% 3f; % 3f]", (double)m.a11,
        (double)m.a12, (double)m.a13, (double)m.a21, (double)m.a22,
        (double)m.a23, (double)m.a31, (double)m.a32, (double)m.a33
    );
}

mat identity() {
    mat m;
    m.a11 = m.a22 = m.a33 = 1;
    m.a12 = m.a13 = m.a21 = m.a23 = m.a31 = m.a32 = 0;
    return m;
}

float det(mat m) {
    return m.a11 * (m.a22 * m.a33 - m.a23 * m.a32) -
           m.a12 * (m.a21 * m.a33 - m.a23 * m.a31) +
           m.a13 * (m.a21 * m.a32 - m.a22 * m.a31);
}

vec col1(mat m) { return (vec){m.a11, m.a21, m.a31}; }

vec col2(mat m) { return (vec){m.a12, m.a22, m.a32}; }

vec col3(mat m) { return (vec){m.a13, m.a23, m.a33}; }

vec row1(mat m) { return (vec){m.a11, m.a12, m.a13}; }

vec row2(mat m) { return (vec){m.a21, m.a22, m.a23}; }

vec row3(mat m) { return (vec){m.a31, m.a32, m.a33}; }

mat from_cols(vec c1, vec c2, vec c3) {
    return (mat){
        c1.x, c2.x, c3.x, c1.y, c2.y, c3.y, c1.z, c2.z, c3.z,
    };
}
