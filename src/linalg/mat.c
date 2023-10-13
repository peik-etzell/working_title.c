#include "mat.h"

#include <math.h>

mat from_euler(float rx, float ry, float rz) {
    float sx = sinf(rx);
    float sy = sinf(ry);
    float sz = sinf(rz);
    float cx = cosf(rx);
    float cy = cosf(ry);
    float cz = cosf(rz);
    return (mat
    ){cy * cz,
      -cx * sz + sx * sy * cz,
      sx * sz + cx * sy * cz,
      cy * sz,
      cx * cz + sx * sy * sz,
      -sx * cz + cx * sy * sz,
      -sy,
      sx * cy,
      cx * cy};
}
