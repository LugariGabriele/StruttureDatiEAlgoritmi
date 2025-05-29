#include "tree.h"
#include <stdlib.h>

static void countNodes(const Node* t, int* count) {
	if (TreeIsEmpty(t)) return;
	countNodes(TreeLeft(t), count);
	(*count)++;
	countNodes(TreeRight(t), count);
}

//creo array mettendo valori nodi in ordine crescente
static void inorderTraversal(const Node* t, ElemType* elems, int* index) {
	if (TreeIsEmpty(t)) return;
	inorderTraversal(TreeLeft(t), elems, index);
	elems[*index] = *TreeGetRootValue(t);
	(*index)++;
	inorderTraversal(TreeRight(t), elems, index);
}

Node* Bst2SkewedTree(const Node* t) {
	if (TreeIsEmpty(t))
	{
		return NULL;
	}


	// devo cercare il valore minore di t quindi andando tutto sx
	ElemType *val_min = NULL;
	Node* current = t;
	while (TreeLeft(current) != NULL) {
		current = TreeLeft(current);  // aggiorna current per scendere a sinistra
	}
	val_min = TreeGetRootValue(current);


	//creo un array di elemtype per salvare i valori mentre facio vista in order
	// Conto i nodi di t per allocare elems
	int count = 0;
	countNodes(t, &count);
	
	ElemType* elems = malloc(count * sizeof(ElemType));

	//vista in ordine
	int index = 0;
	inorderTraversal(t, elems, &index);

	//creo albero nuovo con radice val min
	Node* new_tree = TreeCreateEmpty();
	new_tree = TreeCreateRoot(val_min, NULL, NULL);

	Node* current_new = new_tree;
	for (int i = 1; i < count; i++)
	{
		Node* right_child = TreeCreateRoot(&elems[i], NULL, NULL);
		current_new->right = right_child;
		current_new = right_child;
	}

	free(elems);
	return new_tree;
}
//
//// Funzione di supporto per creare un semplice BST (inserimento iterativo per brevità)
//Node* InsertBST(Node* root, ElemType val) {
//	if (TreeIsEmpty(root)) {
//		return TreeCreateRoot(&val, NULL, NULL);
//	}
//	if (val < *TreeGetRootValue(root)) {
//		Node* left = InsertBST(TreeLeft(root), val);
//		root->left = left;
//	}
//	else if (val > *TreeGetRootValue(root)) {
//		Node* right = InsertBST(TreeRight(root), val);
//		root->right = right;
//	}
//	return root;
//}
//
//int main(void) {
//
//	ElemType vals[] = { 5, 2, 6, 1, 3, 4 };
//	int n = sizeof(vals) / sizeof(vals[0]);
//
//	Node* bst = TreeCreateEmpty();
//	for (int i = 0; i < n; i++) {
//		bst = InsertBST(bst, vals[i]);
//	}
//
//	printf("Albero BST in ordine:\n");
//	TreeWriteStdoutInOrder(bst);
//	printf("\n");
//
//	// Converto il BST in albero skewed
//	Node* skewed = Bst2SkewedTree(bst);
//
//	printf("Albero skewed in ordine:\n");
//	TreeWriteStdoutInOrder(skewed);
//	printf("\n");
//}