#include "tree.h"
#include <stdbool.h>

bool TreeContainsNode(const Node* tree, const Node* node) {

	if (TreeIsEmpty(tree))
	{
		return false;
	}
	
	if (tree==node)
	{
		return true;
	}

	return TreeContainsNode(tree->left, node) || TreeContainsNode(tree->right, node);
}



const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {

	if (t == NULL) return NULL;

	// un nodo è antenato di sè stesso 
	if (t == n1 || t == n2) return t;

	bool n1_in_left = TreeContainsNode(t->left, n1);
	bool n2_in_left = TreeContainsNode(t->left, n2);

	// Se n1 e n2 sono entrambi nel sottoalbero sinistro rispetto t
	if (n1_in_left && n2_in_left) {
		return LowestCommonAncestor(t->left, n1, n2);
	}


	bool n1_in_right = TreeContainsNode(t->right, n1);
	bool n2_in_right = TreeContainsNode(t->right, n2);

	// Se n1 e n2 sono entrambi nel sottoalbero destro
	if (n1_in_right && n2_in_right) {
		return LowestCommonAncestor(t->right, n1, n2);
	}

	// Altrimenti, sono su lati diversi: il nodo corrente è il LCA
	return t;
}