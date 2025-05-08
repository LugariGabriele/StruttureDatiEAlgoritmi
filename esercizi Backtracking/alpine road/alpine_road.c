#include "alpine_road.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool PuntiComunicanti(int* v, int size) {
	if (v[0] != 1) {
		return false;  // subito scarta se il primo elemento non è 1
	}

	int trovato_zero = false;

	for (size_t i = 0; i < size; i++) {
		if (v[i] == 0 && trovato_zero == false) {
			trovato_zero = true;  // ho trovato uno 0
		}
		if (v[i] == 1 && trovato_zero == true) {
			return false;  // trovo 101 → percorso non percorribile
		}
		// se sto già in zona di zeri, continuo
	}

	return true;  // se tutto ok
}

void FindPathRec(const Point* p, size_t p_size, int dh, int i, int* vcurr, int* vbest) {


	if (i == 2) { //ho già decidso partenza e arrivo

		int best_dist = vbest[0] == -1 ? 0 : p[vbest[1]].s - p[vbest[0]].s;
		int curr_dist = p[vcurr[1]].s - p[vcurr[0]].s;

		if (curr_dist > best_dist)
		{
			memcpy(vbest, vcurr, sizeof(int) * 2);
		}

		return;
	}

	if (i == 0) //devo scegliere prima tappa
	{
		for (int j = 0; j < (int)p_size-1; j++) {
			vcurr[0] = j;
			FindPathRec(p, p_size, dh, i + 1, vcurr, vbest);

		}
	}
	else // guardo tappe sucessive a quella iniziale
	{
		for (int k = vcurr[0] + 1; k < (int)p_size; k++)
		{
			//posso raggiugere tappa sucessiva?
			if (abs(p[vcurr[0]].h - p[k].h) > dh)
			{
				break;// dalla tappa iniziale non raggiungo tappe sucessiva se non posso raggiungere j-esima
			}

			vcurr[1] = k;
			FindPathRec(p, p_size, dh, i + 1, vcurr, vbest);
		}
	}

}

int FindPath(const Point* p, size_t p_size, int dh) {

	if (dh < 0) {
		return -1;
	}

	int vcurr[2], vbest[] = { -1,-1 };


	FindPathRec(p, p_size, dh, 0, vcurr, vbest);

	if (vbest[0] == -1)
	{
		return -1;
	}


	for (int j = vbest[0]; j <= vbest[1]; j++) {

		printf("%c: (%3d, %3d) \n", 'A' + j, p[j].s, p[j].h);

	}

	

	return p[vbest[1]].s - p[vbest[0]].s;
}

int main(void) {
	Point p[] = {
		{.s = 0, .h = 10},
		{.s = 40, .h = 19},
		{.s = 60, .h = 19},
		{.s = 110, .h = 25},
		{.s = 170, .h = 17}
	};

	size_t d = sizeof(p) / sizeof(Point);
	int c = FindPath(p, d, 0);

	if (c != -1) {
		printf("Distanza massima: %d\n", c);
	}
	else {
		printf("Nessun percorso valido trovato.\n");
	}

	return 0;
}
