#include "../rendering/primitives/cube.h"

#include <time.h>
#include <unistd.h>

#include "../linalg/triangle.h"
#include "../rendering/render.h"

int main(void) {
    triangles T = {NULL, NULL, 0, 0};

    object cube = new_cube((tfm){identity(), (vec){0, 0, 50}}, 15);
    append_cube(&T, &cube);
    tfm rotation = {from_euler(0.01f, 0.03f, 0), zerovec};

    // clock_t prev_time = clock();
    // float time_diff = 0.1f;
    while (1) {
        cube.transform = mul_tt(cube.transform, rotation);
        cube.update_vertices(&cube);
        render(T);
        fflush(stdout);
        usleep((size_t)(1e6 * 0.01));
        // clock_t time = clock();
        // time_diff = (float)(time - prev_time) / CLOCKS_PER_SEC;
        // prev_time = time;
    }

    free(T.vertices);
    free(T.indices);
    free(cube.vertices);
    free(cube.data);
    return 0;
}
