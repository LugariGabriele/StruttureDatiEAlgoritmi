#include "torrecartoni.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

void TorreCartoniRec(const Cartone *c, int n, int i, Torre *vcurr, Torre *vbest, bool *usati) {
	//ho portato fuori quindi non è più un caso base(quindi non più per le foglie) e riesco a controllare anche sol parziali
	if (vcurr->a > vbest->a) {
		vbest->a = vcurr->a;
		vbest->peso = vcurr->peso;
		vbest->c_size = vcurr->c_size;
		memcpy(vbest->c_ids, vcurr->c_ids, vcurr->c_size * sizeof(int));
	}

	if (n == i) { // sono in una foglia quaindi non posso andare più giù e quindi faccio return per andare dopo funzione ricorsiva
		return;
	}

	for (int j = 0; j < n; ++j) {
		if (!usati[j] && c[j].l >= vcurr->peso) {
			vcurr->a += c[j].a;
			vcurr->peso += c[j].p;
			vcurr->c_ids[vcurr->c_size] = j;
			vcurr->c_size++;

			usati[j] = 1;

			TorreCartoniRec(c, n, i + 1, vcurr, vbest, usati);

			vcurr->a -= c[j].a;
			vcurr->peso -= c[j].p;
			vcurr->c_size--;

			usati[j] = 0;

		}
	}

}

void TorreCartoni(const Cartone *c, size_t n) {
	bool *usati = calloc(n, sizeof(bool));
	Torre vcurr = { .a = 0, .c_ids = malloc(n * sizeof(int)), .c_size = 0, .peso = 0 };
	Torre vbest = { .a = 0, .c_ids = malloc(n * sizeof(int)), .c_size = 0, .peso = 0 };

	TorreCartoniRec(c, (int)n, 0, &vcurr, &vbest, usati);

	for (int i = 0; i < vbest.c_size; ++i) {
		printf("%d\n", vbest.c_ids[i]);
	}
	printf("Altezza: %d cm", vbest.a);

	// Libero la memoria
	free(vcurr.c_ids);
	free(vbest.c_ids);
	free(usati);
}


