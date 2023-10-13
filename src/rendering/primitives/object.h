#ifndef RENDERING_PRIMITIVES_OBJECT_H
#define RENDERING_PRIMITIVES_OBJECT_H

#include "../../linalg/mat.h"
#include "../../linalg/transform.h"

typedef struct object object;
struct object {
    tfm transform;
    void *data;
    void (*update_vertices)(object *);
    vec *vertices;
};

#endif
