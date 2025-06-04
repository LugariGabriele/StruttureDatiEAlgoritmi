#include "minheap.h"
#include <stdlib.h>


size_t ConnectRopes(Heap* ropes) {

	if (HeapIsEmpty(ropes))
	{
		return 0;
	}


	size_t total_cost = 0;


	while (ropes->size > 1) { //O(n-1) fino a quando non ho una corda unica

		// minheap quindi elem più piccolo è il primo

		ElemType first = ropes->data[0];
		ropes->data[0] = ropes->data[--ropes->size]; //faccio pop 
		HeapMinMoveDown(ropes, 0); //O(log n)

		ElemType second = ropes->data[0]; // prendo secondo più piccolo che ora è il primo
		ropes->data[0] = ropes->data[--ropes->size];
		HeapMinMoveDown(ropes, 0); //O(log n)

		ElemType combined = first + second;
		total_cost += combined;

		//rimettiamo la nuova corda nell heap
		HeapMinInsertNode(ropes, &combined); //O(log n)
	}

	return total_cost; //O(n log n)
}

//
//int main(void) {
//	ElemType values[] = { 4, 3, 2, 6 };
//	size_t n = sizeof(values) / sizeof(values[0]);
//
//	// Creazione heap vuoto
//	Heap* h = HeapCreateEmpty();
//
//	// Inserimento dei segmenti nell'heap
//	for (size_t i = 0; i < n; ++i) {
//		HeapMinInsertNode(h, &values[i]);
//	}
//
//	// Calcolo del costo minimo di unione
//	size_t costo = ConnectRopes(h);
//
//	printf("Costo minimo per unire le corde: %zu\n", costo);
//
//
//	return 0;
//}
