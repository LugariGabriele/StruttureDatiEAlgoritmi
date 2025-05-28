#include "minheap.h"

/*

La funzione prende in input un min-heap e l'indice dell' unico nodo che viola le proprietà heap.
La funzione deve spostare il nodo verso l'alto, ovvero scambiarlo con il padre, fino a quando leproprietà min-heap non sono rispettate.

*/

void HeapMinMoveUpRec(Heap* h, int i) {

	//devo controllare se val in i è minore di padre(viola regola) se sì lo scambio e controllo se con nuovo ordinamento rispetta regole

	if (i == 0) {
		// La radice non può essere spostata più in alto quindi se qui abbiamo controllato tutto 
		return;
	}

	int parent = HeapParent(i);

	if (ElemCompare(&h->data[i], &h->data[parent]) < 0) // dato in i è minore di parent
	{
		ElemSwap(&h->data[i], &h->data[parent]); // scambio


		//controllo ora padre di elemento spostato se va bene con quello nuovo
		HeapMinMoveUpRec(h, parent);
	}


}



