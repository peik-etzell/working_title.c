#pragma once

#include "vec.h"

typedef struct {
    vec normal;
    float d;
} plane;

vec project(vec p0, plane plane);
plane create_plane(vec a, vec b, vec c);
