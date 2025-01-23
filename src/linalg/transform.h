#pragma once

#include "mat.h"
#include "vec.h"

typedef struct {
    mat rotation;
    vec translation;
} tfm;

tfm mul_ts(tfm t, float s);
vec mul_tv(tfm t, vec v);
tfm mul_tt(tfm a, tfm b);
tfm rotate(tfm t, mat r);
tfm translate(tfm t, vec v);
