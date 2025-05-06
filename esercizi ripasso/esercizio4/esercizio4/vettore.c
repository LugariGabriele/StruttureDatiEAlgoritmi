#include "vettore.h"
#include <stdlib.h>
#include <string.h>

void Push(struct vettore* v, int d) {
	int* nuovo = realloc(v->data, (v->size + 1) * sizeof(int));
	if (nuovo==NULL)
	{
		return;
	}
	v->data = nuovo;
	v->data[v->size] = d;
	v->size++;
}

int Pop(struct vettore* v) {

	int valore = v->data[0];
	for (size_t i = 1; i < v->size; i++)
	{
		v->data[i - 1] = v->data[i];
	}
	v->size--;
	if (v->size >0)
	{
		int* nuovo = realloc(v->data, v->size * sizeof(int));
		if (nuovo != NULL)
		{
			v->data = nuovo;
		}
	}
	else
	{
		free(v->data);
		v->data = NULL;
	}
	return valore;
}