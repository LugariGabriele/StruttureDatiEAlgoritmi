#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
#include "vettore.h"

//
//void ElemWrite(const ElemType* e, FILE* f) {
//	fprintf(f, "%d", *e);
//}
//
//int ElemRead(FILE* f, ElemType* e) {
//	return fscanf(f, "%d", e);
//}
//
//Vector* VectorReadSorted(const char* filename) {
//
//	FILE* f = fopen(filename, "r");
//	if (!f)
//	{
//		return NULL;
//	}
//
//	Vector* v = malloc(sizeof(Vector));
//	v->capacity = 4; // numero a caso
//	v->size = 0;
//	v->data = malloc(v->capacity * sizeof(ElemType));
//	ElemType e;
//	while (ElemRead(f, &e) == 1) {
//
//		if (v->size == v->capacity)
//		{
//			v->capacity *= 2;
//			v->data = realloc(v->data, v->capacity * sizeof(ElemType));
//
//		}
//		size_t pos = 0;
//		while (pos < v->size && ElemCompare(&v->data[pos], &e) < 0) // <0 se il contenuto di data[pos]< &e
//		{
//			pos++;
//		}
//
//		//sposta a dx per fare spazio
//		for (size_t j = v->size; j > pos; j--)
//		{
//			v->data[j] = v->data[j - 1];
//		}
//
//		v->data[pos] = e;
//		v->size++;
//	}
//
//	fclose(f);
//	return v;
//
//}
//
//int ElemCompare(const ElemType* e1, const ElemType* e2) {
//	return (*e1 > *e2) - (*e1 < *e2);
//}

int main(int argc, char** argv) {

	if (argc != 3)
	{
		fprintf(stderr, "Errore: numero di parametri non corretto.\n");
		return 2;
	}

	char* input_file = argv[1];
	char* output_file = argv[2];

	Vector* v = VectorReadSorted(input_file);
	if (!v) {
		return 1;
	}

	FILE* fout = fopen(output_file, "w");

	if (!fout) {
		return 1;
	}

	for (size_t i = 0; i < v->size; i++)
	{
		ElemWrite(&v->data[i], fout);
		fprintf(fout, "\n");
	}


	fclose(fout);


}