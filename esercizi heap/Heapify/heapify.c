#include "minheap.h"

/*

La funzione crea dinamicamente una min-heap contenente tutti gli elementi del vettore e ne ritorna il puntatore. 
Se il vettore di input � vuoto, la funzione ritornauna heap vuota.


*/


Heap* HeapMinHeapify (const ElemType* v, size_t v_size) {

	Heap* heap = HeapCreateEmpty();

	if (v == NULL || v_size == 0) {
		return heap;
	}


	for (size_t i = 0; i < v_size; i++)
	{
		HeapMinInsertNode(heap, &v[i]);
	}

	return heap;
}



// int main(void) {


// 	ElemType v[] = { 5, 3, 8, 1, 2, 9 };
// 	size_t v_size = sizeof(v) / sizeof(ElemType);

// 	Heap* h = HeapMinHeapify(v, v_size);

// 	printf("Min-heap costruita:\n");
// 	HeapWriteStdout(h);  // stampa heap su stdout

// 	HeapDelete(h);  // libera memoria
// 	return 0;
// }
