#ifndef APLINE_ROAD_H
#define ALPINE_ROAD_H

#include <stdlib.h>

typedef struct {
	int s, h; //x e y 

}Point;

extern int FindPath(const Point* p, size_t p_size, int dh);

#endif // !APLINE_ROAD_H
