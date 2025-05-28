#include "minheap.h"

/*

La funzione prende in input un min-heap e l'indice dell'
unico
nodo che viola le propriet� heap.La funzione deve spostare il nodo verso il basso, ovvero scambiarlo con il figlio minore,
fino aquando le propriet� min-heap non sono rispettate. A differenza della primitiva HeapMinMoveDown() , la funzione deve essere ricorsiva.
*/

void HeapMinMoveDownRec(Heap* h, int i) {

	if (HeapIsEmpty(h))
	{
		return;
	}

	int left = HeapLeft(i); ///ritornano indici
	int right = HeapRight(i);
	int smallest = i; // salvo indice di elem da controllare

	//controllo se figlio sinistro esiste ed � pi� piccolo
	if (left < h->size && ElemCompare(&h->data[left], &h->data[smallest]) < 0)
	{
		smallest = left;
	}

	//controllo se figlio destro esiste ed � pi� piccolo
	if (right < h->size && ElemCompare(&h->data[right], &h->data[smallest]) < 0)
	{
		smallest = right;
	}

	//controllo se pi� piccolo non � nodo i quindi propriet� ordinamentoviolate
	if (smallest != i)
	{
		ElemSwap(&h->data[i], &h->data[smallest]);

		// se arrivati qui adesso devo controllare che vada tutto bene con nuovo ordinamento
		HeapMinMoveDownRec(h, smallest);

	}
}