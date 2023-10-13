#ifndef RENDERING_PRIMITIVES_CUBE_H
#define RENDERING_PRIMITIVES_CUBE_H

#include "../../linalg/transform.h"
#include "../../linalg/triangle.h"
#include "object.h"

object new_cube(tfm transform, float size);
void append_cube(triangles* triangles, object* cube);

#endif
