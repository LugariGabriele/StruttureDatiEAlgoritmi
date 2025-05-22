#include "tree.h"
#include <stdbool.h>

int TreeHeightRec(const Node* t, int altezza) {

	if (t == NULL)
	{
		return altezza - 1; // sono sceso oltre foglia
	}

	// calcolo altezza di ogni sottoalbero
	int altezza_left = TreeHeightRec(t->left, altezza + 1);
	int altezza_right = TreeHeightRec(t->right, altezza + 1);


	return altezza_right > altezza_left ? altezza_right : altezza_left; // ritorno al più alta tra le due
}


int TreeHeight(const Node* t) {

	//altezzo albero corrisponde a numero archi tra radice e nodo + profondo
	if (TreeIsEmpty(t))
	{
		return -1;
	}

	return TreeHeightRec(t, 0);
}

int main(void) {

	// Albero simmetrico:
   //         1
   //       /   \
    //      2     2
	//     / \   / \
    //    3   4 4   3
//		/
//	  10

	Node* t = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 },
				TreeCreateRoot(&(ElemType) { 10 }, NULL, NULL),
				NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL))
	);

	int res = TreeHeight(t);
}
