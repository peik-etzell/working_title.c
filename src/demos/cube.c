#include <time.h>
#include <unistd.h>

#include "../linalg/triangle.h"
#include "../rendering/render.h"
#include "../rendering/primitives/cube.h"

int main(void) {
    tribuf T = {0};
    object cube = new_cube((tfm){identity(), (vec){0, 0, 3}}, 0.1);
    append_cube(&T, &cube);
    mat rot = from_euler(0.01f, 0.02f, 0);
    vec vel = {0, 0, 0};

    while (1) {
        if (cube.transform.translation.z > 0) {
            vel.z -= 0.003f;
        } else {
            vel.z *= -1;
        }
        translate_obj(&cube, vel);
        rotate_obj(&cube, rot);
        update(cube);
        render(T);
        fflush(stdout);
        usleep((size_t)(1e6 * 0.05));
    }

    free(cube.vertices);
    free(cube.data);
    free(T.data);
    return 0;
}
