#include "pulce.h"
#include "math.h"

const Item* CalcolaPercorso(const Item* start, size_t n) {

	if (DListIsEmpty(start))
	{
		return NULL;
	}

	const Item* curr = start;
	size_t salti_fatti = 0;

	while (salti_fatti < n&& curr->value != 0) {

		int direzione = (curr->value) > 0 ? 1 : -1;
		int salti_da_fare = abs(curr->value);

		while (salti_da_fare > 0 && salti_fatti < n) {
			const Item* next;

			if (direzione == 1)
			{
				next = curr->next;
				if (next == NULL) // arrivo a bordo dx
				{
					direzione = -1;
					next = curr->prev;
				}
			}
			else
			{
				next = curr->prev;
				if (next == NULL) // bordo sx
				{
					direzione = 1;
					next = curr->next;
				}
			}

			if (next == NULL) { //sicurezza
				// Non ci sono più direzioni da seguire
				return curr;
			}


			curr = next; // aggiorno curr con posizione nuova
			salti_fatti++;
			salti_da_fare--;

		}
	}

	return curr;
}
//
//int main(void) {
//	int values[] = { 2, -3, 4, 1, 0, 5, -12, 3 };
//	Item* list = DListCreateEmpty();
//	for (int i = sizeof(values) / sizeof(values[0]) - 1; i >= 0; --i) {
//		list = DListInsertHead(&values[i], list);
//	}
//
//	// Trova il nodo con valore 4 come punto di partenza
//	const Item* start = list;
//	while (start != NULL && start->value != 4) {
//		start = start->next;
//	}
//
//	// Calcola percorso
//	const Item* result = CalcolaPercorso(start, 13);
//
//	// Stampa risultato
//	if (result != NULL) {
//		printf("La pulce si è fermata su: %d\n", result->value);
//	}
//	else {
//		printf("La lista è vuota o il punto di partenza è NULL.\n");
//	}
//
//	// Libera memoria
//	DListDelete(list);
//	return 0;
//}