#include "list.h"

void Back2Front(Item** i) {

	if (ListIsEmpty(i) || *i == NULL)
	{
		return;
	}

	Item* prev = NULL;
	Item* curr = *i;

	//trovo ultimo nodo e penultimo
	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	// curr = ultimo nodo
	// *i   = primo nodo
	// prev = penultimo nodo


	curr->next = (*i)->next;
	prev->next = *i;
	(*i)->next = NULL;
	*i = curr;

}

int main(void) {

	int a = 1, b = 2, c = 3, d = 4;

	// Creo la lista: [1, 2, 3, 4]
	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	printf("Lista originale:\n");
	ListWriteStdout(list);
	printf("\n");

	// Chiamo la funzione per scambiare primo e ultimo nodo
	Back2Front(&list);

	printf("Lista dopo Back2Front:\n");
	ListWriteStdout(list);
}