#include "torrecartoni.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

void TorreCartoniRec(const Cartone *c, int n, int i, Torre *vcurr, Torre *vbest, bool *usati) {

	if (n == i){ // se sono folgie controllo se altezza configurazione corrente è migliore
		if (vcurr->a > vbest->a) {
			vbest->a = vcurr->a;
			vbest->peso = vcurr->peso;
			vbest->c_size = vcurr->c_size;
			memcpy(vbest->c_ids, vcurr->c_ids, vcurr->c_size * sizeof(int)); // copio gli indici (l'array) di curr in best
		}
		return;// sono in foglia e non posso andare più avanti di così quini torno indietro
	}

	bool rami_esplorati = false;
	for(int j = 0; j < n; ++j){ // scorro pacchi (ho n-1 sottoscelte)
		if (!usati[j] && c[j].l >= vcurr->peso){ // se non l'ho ancora usato pacco j e la sua tolleraza sopporta il peso della torre posso metterlo sotto
			rami_esplorati = true;
			vcurr->a += c[j].a;
			vcurr->peso += c[j].p;
			vcurr->c_ids[vcurr->c_size] = j; // va bene anche [i]
			vcurr->c_size++;

			usati[j] = 1; // metto il pacco usato a true 

			TorreCartoniRec(c, n, i + 1, vcurr, vbest, usati); // vado a livello i=4

			//pulisco per la prossima scelta dato che sono tornato indietro di un passo i=3 se sono arrivato qui
			//posso non cabiare c_ids[vcurrsize] dato che verrà sovraiscritto
			vcurr->a -= c[j].a;
			vcurr->peso -= c[j].p;
			vcurr->c_size--;

			usati[j] = 0; //rimetto usati a false

		}
	}

	//la variabile rami esplorati serve per tenere in considerazione anche le soluzioni parziali come soluzioni (faccio fun ricorsiva con n per far finta che sia foglia
	// e quindi entrare nel controllo con best) !! meglio versione v1 
	if (!rami_esplorati){
		TorreCartoniRec(c, n, n, vcurr, vbest, usati);
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


