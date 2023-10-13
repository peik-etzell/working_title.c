#ifndef LINALG_TRIANGLE_H
#define LINALG_TRIANGLE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "vec.h"

typedef struct {
    vec **vertices;
    size_t *indices;
    size_t n_verts;
    size_t n_inds;
} triangles;

static void ensure_capacity(triangles *T, size_t n_verts, size_t n_inds) {
    size_t v_cap = 0x1;
    size_t i_cap = 0x1;
    while (v_cap < n_verts) v_cap <<= 1;
    while (i_cap < n_inds) i_cap <<= 1;
    T->vertices = realloc(T->vertices, v_cap * sizeof(vec *));
    T->indices = realloc(T->indices, i_cap * sizeof(size_t));
}

static void append_triangles(
    triangles *T, vec *verts, size_t n_verts, size_t *inds, size_t n_inds
) {
    ensure_capacity(T, T->n_verts + n_verts, T->n_inds + n_inds);
    for (size_t ind = 0; ind < n_inds; ++ind) {
        T->indices[T->n_inds] = T->n_verts + inds[ind];
        T->n_inds++;
    }
    for (size_t vert = 0; vert < n_verts; ++vert) {
        T->vertices[T->n_verts] = verts + vert;
        T->n_verts++;
    }
}

#endif
