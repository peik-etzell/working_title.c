#pragma once

#include <assert.h>

#include "../../linalg/mat.h"
#include "../../linalg/transform.h"
#include "../../linalg/vec.h"
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

void translate_obj(object *obj, vec t);

void rotate_obj(object *obj, mat r);
