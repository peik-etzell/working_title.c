#include "line.h"

#include "../rendering/pixel.h"

/**
 * sign(x,y) = (x2 - x1)(y1 - y) - (x1 - x)(y2 - y1)
 * = (x1 - x2)y + (y2 - y1)x + (x2 - x1)y1 - (y2 - y1)x1
 * => s_x := (y2 - y1)
 * => s_y := (x1 - x2)
 * => const := -s_x * x1 - s_y * y1
 */
line line_from_points(pixelf a, pixelf b) {
    float x_c = b.y - a.y;
    float y_c = a.x - b.x;
    return (line){x_c, y_c, -a.x * x_c - a.y * y_c};
}

float signed_distance(line l, pixelf p) {
    return l.x_scale * p.x + l.y_scale * p.y + l.constant;
}
