#ifndef LINALG_LINE_H
#define LINALG_LINE_H

#include "../rendering/pixel.h"

typedef struct {
    float x_scale;
    float y_scale;
    float constant;
} line;

line line_from_points(pixelf a, pixelf b);
float signed_distance(line l, pixelf p);

#endif
