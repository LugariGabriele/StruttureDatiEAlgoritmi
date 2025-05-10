#include "vettore.h"
#include <stdlib.h>
#include <stdio.h>


void VectorSort(Vector* v) {
	if (v == NULL)
	{
		return;
	}

	//faccio bubble sort
	int ordinato = 0;
	size_t size = v->size;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (int i = 0; i < size - 1; i++)
		{
			if (ElemCompare(&v->data[i], &v->data[i + 1]) > 0) // data i maggiore di i+1
			{
				ElemSwap(&v->data[i], &v->data[i + 1]);
				ordinato = 0;
			}
		}
		size--;
	}
}


//int main(void) {
//	Vector v;
//	v.size = 5;
//	v.capacity = 5;
//	v.data = malloc(v.capacity * sizeof(ElemType));
//
//	// Inserisci valori (esempio: 5, 2, 9, 1, 4)
//	v.data[0] = 5;
//	v.data[1] = 2;
//	v.data[2] = 9;
//	v.data[3] = 1;
//	v.data[4] = 4;
//
//	VectorSort(&v);
//
//}
