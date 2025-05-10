#include "vettore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Vector* VectorRead(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return NULL;
	}

	Vector* v = malloc(sizeof(Vector));

	v->capacity = 4; // numero a caso
	v->size = 0;
	v->data = malloc(v->capacity * sizeof(ElemType));

	ElemType e;
	while (ElemRead(f, &e)==1) {
		if (v->size == v->capacity)
		{
			v->capacity *= 2;
			v->data = realloc(v->data, v->capacity * sizeof(ElemType));

		}

		v->data[v->size++] = e;
	}

	fclose(f);
	return v;
}

Vector* VectorReadSorted(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return NULL;
	}

	Vector* v = malloc(sizeof(Vector));
	v->capacity = 4; // numero a caso
	v->size = 0;
	v->data = malloc(v->capacity * sizeof(ElemType));
	ElemType e;
	while (ElemRead(f, &e)==1) {

		if (v->size == v->capacity)
		{
			v->capacity *= 2;
			v->data = realloc(v->data, v->capacity * sizeof(ElemType));

		}
		size_t pos = 0;
		while (pos < v->size && ElemCompare(&v->data[pos], &e) < 0) // <0 se il contenuto di data[pos]< &e
		{
			pos++;
		}

		//sposta a dx per fare spazio
		for (size_t j = v->size; j > pos; j--)
		{
			v->data[j] = v->data[j - 1];
		}

		v->data[pos] = e;
		v->size++;
	}

	fclose(f);
	return v;

}

int main(void) {

	Vector* v = VectorRead("input_int_01.txt");
}