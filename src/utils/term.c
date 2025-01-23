#include "term.h"

#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void clear_screen(void) { fputs("\x1B[2J", stdout); }

termsz get_termsize(void) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return (termsz){ws.ws_col, ws.ws_row};
}

void cursor_home(void) { fputs("\x1B[;H", stdout); }

void cursor_move(size_t row, size_t col) { printf("\x1B[%zu;%zuH", row, col); }

void cursor_prev_line(void) { fputs("\x1B[F", stdout); }

void cursor_next_line(void) { fputs("\x1B[E", stdout); }
