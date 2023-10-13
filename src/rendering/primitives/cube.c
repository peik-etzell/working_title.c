#include "cube.h"

#include "../../utils/macros.h"

size_t BOX_INDICES[36];
int INDICES_INIT = 0;

size_t* indices() {
    if (!INDICES_INIT) {
        size_t corners[4] = {0b000, 0b011, 0b101, 0b110};
        size_t i = 0;
        for (size_t j = 0; j < 4; ++j) {
            size_t c = corners[j];
            BOX_INDICES[i++] = c;
            BOX_INDICES[i++] = c ^ 0b001;
            BOX_INDICES[i++] = c ^ 0b100;
            BOX_INDICES[i++] = c;
            BOX_INDICES[i++] = c ^ 0b010;
            BOX_INDICES[i++] = c ^ 0b001;
            BOX_INDICES[i++] = c;
            BOX_INDICES[i++] = c ^ 0b100;
            BOX_INDICES[i++] = c ^ 0b010;
        }
        INDICES_INIT = 1;
    }
    return BOX_INDICES;
}

typedef struct {
    float size;
} cube_data;

void append_cube(triangles* triangles, object* cube) {
    append_triangles(triangles, cube->vertices, 8, indices(), 36);
}

static void update_vertices(object* obj) {
    float half_size = ((cube_data*)obj->data)->size * 0.5f;
    for (int i = 0b000; i < 8; ++i) {
        obj->vertices[i] = mul_tv(
            obj->transform,
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
