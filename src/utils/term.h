#pragma once

#include <asm-generic/ioctls.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include <unistd.h>

typedef struct {
    size_t w;
    size_t h;
} termsz;

termsz get_termsize(void);

void cursor_home(void);
void cursor_move(size_t row, size_t col);
void cursor_prev_line(void);
void cursor_next_line(void);
void clear_screen(void);
