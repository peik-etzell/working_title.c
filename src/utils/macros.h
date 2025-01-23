#pragma once

#include <math.h>

#define new(type, count) (type*)malloc(count * sizeof(type))
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min3(a, b, c) min((a), min((b), (c)))
#define max3(a, b, c) max((a), max((b), (c)))

static inline float boundf(float val, float lo, float hi) {
    return fminf(hi, fmaxf(lo, val));
}
