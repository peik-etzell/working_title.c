#ifndef LINALG_TRIANGLE_H
#define LINALG_TRIANGLE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/buf.h"
#include "vec.h"

typedef struct {
    vec *a;
    vec *b;
    vec *c;
} tri;

DECL_BUF(tribuf, tri);

#endif
