#include "../rendering/primitives/cube.h"

#include <time.h>
#include <unistd.h>

#include "../linalg/triangle.h"
#include "../rendering/primitives/rectangle.h"
#include "../rendering/render.h"

int main(void) {
    tribuf T = {0};
    object cube = new_cube((tfm){identity(), (vec){0, 0, 3}}, 0.1);
    append_cube(&T, &cube);
    mat rot = from_euler(0.01f, 0.02f, 0);
    vec vel = {0, 0, 0};

    // object floor = new_rectangle(
    //     (tfm){from_euler(-(float)M_PI_2, 0, 0), (vec){0, 50, 50}}, 300, 400
    // );
    // append_rectangle(&T, &floor);

    while (1) {
        if (cube.transform.translation.y < 10) {
            // vel.y += 0.03f;
        } else {
            // vel.y *= -1;
        }
        if (cube.transform.translation.z > 0) {
            vel.z -= 0.003f;
        } else {
            vel.z *= -1;
        }
        translate_obj(&cube, vel);
        rotate_obj(&cube, rot);
        update(cube);
        // update(floor);
        render(T);
        fflush(stdout);
        usleep((size_t)(1e6 * 0.05));
    }

    free(cube.vertices);
    free(cube.data);
    return 0;
}
