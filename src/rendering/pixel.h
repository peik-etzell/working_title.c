#pragma once

typedef struct {
    float x;
    float y;
} pixelf;

typedef struct {
    int x;
    int y;
} pixel;

char lum2char(float luminance);
