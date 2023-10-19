#include "rectangle.h"

#include <stddef.h>

#include "../../utils/macros.h"
#include "object.h"

typedef struct {
    float size_x;
    float size_y;
} rect_data;

static void update_vertices(object* rect) {
    for (int i = 0b00; i < 4; ++i) {
        rect_data data = *(rect_data*)rect->data;
        float hx = data.size_x * 0.5f;
        float hy = data.size_y * 0.5f;
        rect->vertices[i] = mul_tv(
            rect->transform,
            (vec){
                (i & 0b01) ? hx : -hx,
                (i & 0b10) ? hy : -hy,
                0,
            }
        );
    }
}

object new_rectangle(tfm transform, float size_x, float size_y) {
    rect_data* data = new (rect_data, 1);
    data->size_x = size_x;
    data->size_y = size_y;
    return (object){transform, data, update_vertices, new (vec, 4)};
}

void append_rectangle(tribuf* T, const object* rect) {
    tribuf_append(
        T,
        (tri
        ){rect->vertices + 0b00, rect->vertices + 0b10, rect->vertices + 0b01}
    );
    tribuf_append(
        T,
        (tri
        ){rect->vertices + 0b11, rect->vertices + 0b01, rect->vertices + 0b10}
    );
}
