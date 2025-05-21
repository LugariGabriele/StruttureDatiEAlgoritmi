#include "tree.h"
#include <stdbool.h>

Node* DeleteBstNode(Node* n, const ElemType* key) {

	if (n == NULL) return NULL;


	Node* parent = NULL;
	Node* curr = n;



	// Trova il nodo da eliminare e il suo genitore
	while (curr != NULL && ElemCompare(key, &curr->value) != 0) {
		parent = curr;

		if (ElemCompare(key, &curr->value) < 0) // valore > key quindi cerco a sx
		{
			curr = TreeLeft(curr);
		}

		else // key> quindi vado a dx
		{
			curr = TreeRight(curr);
		}
	}

	// Nodo non trovato
	if (curr == NULL) {
		return n;
	}


	bool delete_pos_left = parent->left == curr ? 1 : 0;


	// CASO 1: nodo da eliminare è foglia(quindi ha 0 figli)

	if (TreeIsLeaf(curr))
	{
		// devo capire da che lato di parent è il figlio da eliminare
		if (delete_pos_left)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}


	//CASO 2: nodo da eliminare ha un figlio
	else if (curr->left == NULL || curr->right == NULL)
	{
		Node* child = (curr->left != NULL) ? curr->left : curr->right;
		if (delete_pos_left)
		{
			parent->left = child;
		}

		else
		{
			parent->right = child;
		}
	}


	//CASO 3: nodo da eliminare ha due figli
	else
	{
		//cerco sucessore (elemento più a sinistra di sottoalbero dx)
		Node* succ = curr->right;
		Node* succ_parent = curr;


		while (succ->left != NULL) { // vado più a sx possibile
			succ_parent = succ;
			succ = succ->left;
		}

		// Copia il valore del successore nel nodo da eliminare
		curr->value = succ->value;


		//prendo figlio dx di successore se lo ha e lo metto dove era sucessore (in caso di foglia non fa niente)

		bool succ_pos = succ_parent->left == succ ? 1 : 0;

		Node* succ_child = succ->right;
		if (succ_pos) // succ era a sx del padre
			succ_parent->left = succ_child;
		else
			succ_parent->right = succ_child;

	}

	return n;
}