#ifndef RENDERING_PRIMITIVES_OBJECT_H
#define RENDERING_PRIMITIVES_OBJECT_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../linalg/mat.h"
#include "../../linalg/transform.h"
#include "../../utils/buf.h"

#define update(object) object.update_vertices(&object)

typedef struct object object;
struct object {
    tfm transform;
    void *data;
    void (*update_vertices)(object *);
    vec *vertices;
};

DECL_BUF(objbuf, object);

static void translate_obj(object *obj, vec t) {
    obj->transform = translate(obj->transform, t);
}

static void rotate_obj(object *obj, mat r) {
    assert(fabsf(det(r) - 1.f) < 1e-6f);
    obj->transform = rotate(obj->transform, r);
}

#endif
