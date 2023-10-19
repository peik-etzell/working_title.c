#include "cube.h"

#include <stddef.h>

#include "../../utils/macros.h"
#include "object.h"

typedef struct {
    float size;
} cube_data;

void append_cube(tribuf* T, const object* cube) {
    size_t corners[4] = {0b000, 0b011, 0b101, 0b110};
    for (size_t j = 0; j < 4; ++j) {
        size_t c = corners[j];
        tribuf_append(
            T,
            (tri){
                cube->vertices + c,
                cube->vertices + (c ^ 0b001),
                cube->vertices + (c ^ 0b100),
            }
        );
        tribuf_append(
            T,
            (tri){
                cube->vertices + c,
                cube->vertices + (c ^ 0b010),
                cube->vertices + (c ^ 0b001),
            }
        );
        tribuf_append(
            T,
            (tri){
                cube->vertices + c,
                cube->vertices + (c ^ 0b100),
                cube->vertices + (c ^ 0b010),
            }
        );
    }
}

static void update_vertices(object* cube) {
    float half_size = ((cube_data*)cube->data)->size * 0.5f;
    for (int i = 0b000; i < 8; ++i) {
        cube->vertices[i] = mul_tv(
            cube->transform,
            (vec){
                (i & 0b001) ? half_size : -half_size,
                (i & 0b010) ? half_size : -half_size,
                (i & 0b100) ? half_size : -half_size,
            }
        );
    }
}

object new_cube(tfm transform, float size) {
    cube_data* data = new (cube_data, 1);
    data->size = size;
    return (object){transform, data, update_vertices, new (vec, 8)};
}
