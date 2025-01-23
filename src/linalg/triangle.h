#pragma once

#include "../utils/buf.h"
#include "vec.h"

typedef struct {
    vec *a;
    vec *b;
    vec *c;
} tri;

DECL_BUF(tribuf, tri);
