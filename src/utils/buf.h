#ifndef UTILS_BUF_H
#define UTILS_BUF_H

#include "macros.h"

#define DECL_BUF(NAME, TYPE)                                                   \
    typedef struct {                                                           \
        TYPE* data;                                                            \
        size_t n;                                                              \
        size_t cap;                                                            \
    } NAME;                                                                    \
    static void NAME##_append(NAME* buf, TYPE elem) {                          \
        if (buf->n >= buf->cap) {                                              \
            buf->cap = max(8UL, buf->cap * 2);                                 \
            buf->data = reallocarray(buf->data, buf->cap, sizeof(*buf->data)); \
        }                                                                      \
        buf->data[buf->n++] = elem;                                            \
    }

DECL_BUF(intbuf, int);
DECL_BUF(floatbuf, float);

#endif
