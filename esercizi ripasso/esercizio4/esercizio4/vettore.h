#ifndef VETTORE_H
#define VETTORE_H

#include<stddef.h>
struct vettore
{
	int* data;
	size_t size;
};

extern void Push(struct vettore* v, int d);
extern int Pop(struct vettore* v);


#endif // !VETTORE.H

