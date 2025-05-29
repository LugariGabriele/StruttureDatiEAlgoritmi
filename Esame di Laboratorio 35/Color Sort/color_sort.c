#include <stdlib.h>
#include <stdint.h>  

void ColorSort(uint8_t* v, size_t v_size) {

	//tutti gli 0 sono all inizio, tutti gli 1 in mezzo e tutti i 2 alla fine 

	if (v_size==0)
	{
		return;
	}

	size_t low = 0; // posizione dove va inserito il prossimo 0(inizio)
	size_t mid = 0; // elem da esaminare
	size_t high = v_size - 1; // posizione dove inserire il prossimo 2 (fine)

	while (mid <= high && v_size > 0) {
		if (v[mid]==0)
		{	
			//scambio elemento corrente con indice low(inizio)
			uint8_t temp = v[low];
			v[low] = v[mid];
			v[mid] = temp;
			mid++;
			low++;
		}
		else if (v[mid] == 1) {
			mid++; // lo lascio lì dov'è , in mezzo
		}
		else
		{
			//scambio val corrente con quello in fondo e poi decrementiamo high
			uint8_t temp = v[mid];
			v[mid] = v[high];
			v[high] = temp;
			if (high == 0) break;  // per evitare underflow su size_t
			high--;

		}
	}


	//O(n) con n=v_size
}