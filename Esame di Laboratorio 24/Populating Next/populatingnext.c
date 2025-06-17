#include "tree.h"

void PopulatingNextRec(Node* curr, Node** prev) {

	if (curr == NULL)
	{
		return;
	}


	PopulatingNextRec(curr->left, prev);

	if (*prev != NULL) //dopo essere arrivato in fondo a sx non è più null
	{
		(*prev)->next = curr; //imposto il next del nodo prima in quello corispondente
	}


	*prev = curr; // salvo nodo es arrivo a 0 e me lo salvo

	PopulatingNextRec(curr->right, prev);

}
//
//	   3
//	  / \
//   1   5
//  / \   \
// 0   2   6


void PopulatingNext(Node * t) {

	if (TreeIsEmpty(t))
	{
		return;
	}

	Node* prev = NULL;
	PopulatingNextRec(t, &prev);

}


