#include "minheap.h"

/*

La funzione prende in input un min-heap e l'indice dell' unico nodo che viola le propriet� heap.
La funzione deve spostare il nodo verso l'alto, ovvero scambiarlo con il padre, fino a quando lepropriet� min-heap non sono rispettate.

*/

void HeapMinMoveUpRec(Heap* h, int i) {

	//devo controllare se val in i � minore di padre(viola regola) se s� lo scambio e controllo se con nuovo ordinamento rispetta regole

	if (i == 0) {
		// La radice non pu� essere spostata pi� in alto quindi se qui abbiamo controllato tutto 
		return;
	}

	int parent = HeapParent(i);

	if (ElemCompare(&h->data[i], &h->data[parent]) < 0) // dato in i � minore di parent
	{
		ElemSwap(&h->data[i], &h->data[parent]); // scambio


		//controllo ora padre di elemento spostato se va bene con quello nuovo
		HeapMinMoveUpRec(h, parent);
	}


}



