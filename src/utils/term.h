#ifndef UTILS_TERM_H
#define UTILS_TERM_H

#include <stddef.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

typedef struct {
    size_t w;
    size_t h;
} termsz;

static termsz get_termsize(void) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return (termsz){ws.ws_col, ws.ws_row};
}

static inline void cursor_home(void) {
    putchar(0x1B);
    printf("[;H");
}
static inline void cursor_move(size_t row, size_t col) {
    putchar(0x1B);
    printf("[%zu;%zuH", row, col);
}
static inline void cursor_prev_line(void) {
    putchar(0x1B);
    printf("[F");
}
static inline void cursor_next_line(void) {
    putchar(0x1B);
    printf("[E");
}
static inline void clear_screen(void) {
    putchar(0x1B);
    printf("[2J");
}

#endif
