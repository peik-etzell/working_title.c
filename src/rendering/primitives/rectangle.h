#ifndef RENDERING_PRIMITIVES_RECTANGLE_H
#define RENDERING_PRIMITIVES_RECTANGLE_H

#include "../../linalg/transform.h"
#include "../../linalg/triangle.h"
#include "object.h"

object new_rectangle(tfm transform, float size_x, float size_y);
void append_rectangle(tribuf* T, const object* rect);

#endif
