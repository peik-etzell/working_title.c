#ifndef LINALG_TRANSFORM_H
#define LINALG_TRANSFORM_H

#include "mat.h"
#include "vec.h"

typedef struct {
    mat rotation;
    vec translation;
} tfm;

static tfm mul_ts(tfm t, float s) {
    return (tfm){mul_ms(t.rotation, s), mul_vs(t.translation, s)};
}
static vec mul_tv(tfm t, vec v) {
    return add(mul_mv(t.rotation, v), t.translation);
}
static tfm mul_tt(tfm a, tfm b) {
    return (tfm
    ){mul_mm(a.rotation, b.rotation),
      add(a.translation, mul_mv(a.rotation, b.translation))};
}

#endif
