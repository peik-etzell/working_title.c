#include "object.h"

#include <assert.h>
#include <math.h>

#include "../../linalg/mat.h"
#include "../../linalg/transform.h"
#include "../../linalg/vec.h"

void translate_obj(object *obj, vec t) {
    obj->transform = translate(obj->transform, t);
}

void rotate_obj(object *obj, mat r) {
    assert(fabsf(det(r) - 1.f) < 1e-6f);
    obj->transform = rotate(obj->transform, r);
}
