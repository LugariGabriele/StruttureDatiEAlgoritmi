#include "robot_mod.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void DivisoriRighe(size_t cols) {
	printf("+");
	for (size_t i = 0; i < cols; i++)
	{
		printf("---+");
	}
	printf("\n");
}

void FindPathRec(const struct Grid* gcurr, int r, int c, int size, int* nsol, int nstep, int max_moves) {

	if (r == gcurr->rows - 1 && c == gcurr->cols - 1 && nstep <= max_moves) //caso base, sono arrivato in fondo e in numero giusto mosse
	{
		(*nsol)++;
		printf("Sol %d: \n", *nsol);
		PrintGrid(gcurr);
		return;
	}

	int next_index = (r + 1) * gcurr->cols + c;
	if (r < gcurr->rows - 1 && gcurr->cells[next_index] != -1)
	{   //sposto giù
		if (gcurr->cells[next_index] == 0) { //controllo se cella libera
			gcurr->cells[next_index] = nstep;
			FindPathRec(gcurr, r + 1, c, size, nsol, nstep + 1, max_moves);
			gcurr->cells[next_index] = 0;
		}
	}

	next_index = r * gcurr->cols + (c + 1);

	if (c < gcurr->cols - 1 && gcurr->cells[next_index] != -1)
	{	//mi sposto a destra

		if (gcurr->cells[next_index] == 0)
		{
			gcurr->cells[next_index] = nstep;
			FindPathRec(gcurr, r, c + 1, size, nsol, nstep + 1, max_moves);
			gcurr->cells[next_index] = 0;
		}

	}

	next_index = (r - 1) * gcurr->cols + c;

	if (r > 0 && gcurr->cells[next_index] != -1) {
		//sposto su

		if (gcurr->cells[next_index] == 0)
		{
			gcurr->cells[next_index] = nstep;
			FindPathRec(gcurr, r - 1, c, size, nsol, nstep + 1, max_moves);
			gcurr->cells[next_index] = 0;
		}
	}

	//NON RICHIESTO MA SENNOò FAREBBE SEMPRE UNA SOL TUTTAIN BASSO		
	next_index = r * gcurr->cols + (c - 1);

	if (c > 0 && gcurr->cells[(r * gcurr->cols + (c - 1))] != -1) {
		// sposto a sinistra
		if (gcurr->cells[next_index] == 0) {
			gcurr->cells[next_index] = nstep;
			FindPathRec(gcurr, r, c - 1, size, nsol, nstep + 1, max_moves);
			gcurr->cells[next_index] = 0;
		}
	}
}


int FindPaths(const struct Grid* g, int max_moves) {

	if (max_moves < 0)
	{
		max_moves = INT_MAX;
	}

	int* vcurr = calloc(g->rows * g->cols, sizeof(int));
	int nsol = 0;
	for (size_t i = 0; i < (g->cols * g->rows); i++)
	{
		vcurr[i] = g->cells[i];
	}

	struct Grid gcurr = { .rows = g->rows,
						.cols = g->cols,
						.cells = calloc((g->cols * g->rows), sizeof(int)),
	};

	memcpy(gcurr.cells, vcurr, (g->cols * g->rows) * sizeof(int));
	gcurr.cells[gcurr.cols - 1] = 1; // posiziono in alto a dx
	FindPathRec(&gcurr, 0, gcurr.cols - 1, (g->cols * g->rows), &nsol, 2, max_moves);


	free(vcurr);
	free(gcurr.cells);

	return nsol;
}


void PrintGrid(const struct Grid* g) {

	for (size_t i = 0; i < g->rows; i++)
	{
		DivisoriRighe(g->cols);
		printf("|");
		for (size_t j = 0; j < g->cols; j++)
		{
			if (g->cells[i * g->cols + j] == -1) {
				printf(" %c |", 'B');

			}
			else
			{
				printf(" %-1d |", g->cells[i * g->cols + j]);
			}
		}
		printf("\n");
	}
	DivisoriRighe(g->cols);
	printf("\n");

}


int main(void) {
	struct Grid* g = malloc(sizeof(struct Grid));
	g->cols = 5;
	g->rows = 3;
	g->cells = calloc((g->cols * g->rows), sizeof(int));
	g->cells[1] = -1;
	g->cells[8] = -1;

	printf("Grid base: \n");
	PrintGrid(g);
	FindPaths(g, 10);
}
