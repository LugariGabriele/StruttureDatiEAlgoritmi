#ifndef COLORMAP_H
#define COLORMAP_H

#include <stdlib.h>
#include <stdbool.h>

extern int ColorMap(const struct SquareMatrix* m, const char* c);

struct SquareMatrix
{
	size_t side;
	bool* data;
};

#endif // !COLORMAP_H
