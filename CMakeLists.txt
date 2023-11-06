cmake_minimum_required(VERSION 3.8)
project(working_title)

add_compile_options(
  "$<$<CONFIG:DEBUG>:-O0>"
  -Wall
  -Wextra
  -Wconversion
  -Wdouble-promotion
  -Wno-unused-parameter
  -Wno-unused-function
  -fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LINALG ./src/linalg/mat.c ./src/linalg/plane.c ./src/linalg/line.c)
set(RENDERING
    ./src/rendering/viewplane.c ./src/rendering/pixel.c
    ./src/rendering/primitives/cube.c ./src/rendering/primitives/rectangle.c
    ./src/rendering/render.c)

add_executable(${PROJECT_NAME} ./src/demos/cube.c ${LINALG} ${RENDERING})
target_link_libraries(${PROJECT_NAME} PRIVATE m)
