#include "../rendering/primitives/cube.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../linalg/mat.h"
#include "../linalg/transform.h"
#include "../linalg/triangle.h"
#include "../linalg/vec.h"
#include "../rendering/primitives/object.h"
#include "../rendering/render.h"

static int stop = 0;

static void catch_sigint(int signo) {
    (void)signo;
    stop = 1;
}

int main(void) {
    if (signal(SIGINT, catch_sigint) == SIG_ERR) {
        fputs("Failed to set signal handler.\n", stderr);
        return EXIT_FAILURE;
    }

    tribuf T = {0};
    object cube = new_cube((tfm){identity(), (vec){0, 0, 3}}, 0.1f);
    append_cube(&T, &cube);
    mat rot = from_euler(0.01f, 0.02f, 0);
    vec vel = {0, 0, 0};

    while (!stop) {
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
    return EXIT_SUCCESS;
}
