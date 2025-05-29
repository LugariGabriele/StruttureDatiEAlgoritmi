#include "merge.h"
#include <stdlib.h>


Item* MergeInBetween(Item* i1, Item* i2, int l, int r) {

	if (ListIsEmpty(i1))
	{
		return i2;
	}

	Item* prec_L = NULL; // nodo prima di L
	Item* curr = i1;

	//scorro fino a nodo indice L
	for (int i = 0; i < l; i++)
	{
		prec_L = curr;
		curr = curr->next;
	}

	// creo un altro puntatore per puntare a elemento di indice R(fine elimina)
	Item* post_R = curr;
	for (int i = l; i <=r; i++)
	{
		Item* toDelete = post_R;
		post_R = post_R->next;
		free(toDelete); // libero i nodi da l a r inclusi
	}
	
	// Trovo la fine della lista i2
	Item* fine_i2 = i2;
	if (fine_i2 != NULL) {
		while (fine_i2->next != NULL) {
			fine_i2 = fine_i2->next;
		}
	}


	//collego i2 nel buco
	if (prec_L == NULL) {
		// sostituzione dalla testa (l == 0)
		if (i2 == NULL) {
			// i2 vuota, la nuova testa è post_R
			return post_R;
		}
		else {
			// i2 non vuota
			fine_i2->next = post_R;
			return i2;
		}
	}
	else {
		// l > 0, collego prec_L a i2 o post_R
		if (i2 == NULL) {
			prec_L->next = post_R;
		}
		else {
			prec_L->next = i2;
			fine_i2->next = post_R;
		}
		return i1;
	}
}