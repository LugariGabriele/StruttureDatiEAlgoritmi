#include "colormap.h"
#include <stdio.h>
#include <string.h>

int ColorMapRec(const struct SquareMatrix* m, const char* c, int i, char* vcurr, int* nsol, int size) {
	if (i == size) // mappa tutta colorata 
	{
		for (size_t j = 0; j < size; j++)
		{
			for (size_t g = 0; g < size; g++) {

				if (vcurr[j] == vcurr[g] && m->data[j * m->side + g] == 1 && j != g) //controllo se dato j ho colorato uguale ad adiacenti 
				{
					return;
				}
			}
		}

		(*nsol)++;

		for (size_t k = 0; k < size; k++)
		{
			printf("%d -> %c; ",k, vcurr[k]);
		}
		printf("\n");
		return;
	}

	for (size_t j = 0; j < strlen(c) ; j++)
	{
		vcurr[i] = c[j];
		ColorMapRec(m, c, i + 1, vcurr, nsol, size);
	}
}



int ColorMap(const struct SquareMatrix* m, const char* c) {

	if (c == NULL)
	{
		return 0;
	}

	int nsol = 0;
	char* vcurr = calloc(m[0].side, sizeof(char));
	int size = m->side;

	ColorMapRec(m, c, 0, vcurr, &nsol, size);

	free(vcurr);

	return nsol;
}

void setAdjacences(struct SquareMatrix* m, int a, const int* b, size_t b_size) {
	for (size_t i = 0; i < b_size; i++)
	{
		m->data[a * m->side + b[i]] = 1;
		m->data[b[i] * m->side + a] = 1;
	}
}

void PrintMatrix(struct SquareMatrix* m) {
	for (size_t r = 0; r < m->side; r++)
	{
		for (size_t c = 0; c < m->side; c++) {
			printf("[%d]", m->data[r * m->side + c]);
		}
		puts("");
	}
}

int main(void) {
	int s;
	{
		size_t mside = 3;
		struct SquareMatrix m = { .data = calloc(mside * mside, sizeof(bool)), .side = mside };
		int i0[] = { 0,1,2 };
		setAdjacences(&m, 0, i0, sizeof(i0) / sizeof(int));
		int i1[] = { 0,1 };
		setAdjacences(&m, 1, i1, sizeof(i1) / sizeof(int));
		int i2[] = { 0,2 };
		setAdjacences(&m, 2, i2, sizeof(i2) / sizeof(int));

		PrintMatrix(&m);
		puts("");
		s = ColorMap(&m, "rv");
	}
}