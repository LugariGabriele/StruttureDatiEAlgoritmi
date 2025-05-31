#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <stdlib.h>
struct Matrix {
    size_t rows, cols;
    char* data;
};
extern void FloodFill(struct Matrix* img, int x, int y, char old_color, char new_color);
#endif // !FLOODFILL_H
