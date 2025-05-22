#include "tree.h"
#include <stdbool.h>

bool TreeAreIdentical(Node* t1, Node* t2) {

	//due alberi vuoti sono identici
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}

	// devono essere bilanciati per forza per essere identici
	if (t1 == NULL || t2 == NULL)
	{
		return false;
	}

	bool uguali_valore = false;

	uguali_valore = ElemCompare(&t1->value, &t2->value) == 0;

	bool uguali_sx = TreeAreIdentical(t1->left, t2->left);
	bool uguali_dx = TreeAreIdentical(t1->right, t2->right);

	if (uguali_valore && uguali_sx && uguali_dx) {
		return true;
	}
	else {
		return false;
	}
}


int main(void) {


	// Albero simmetrico:
   //         1
   //       /   \
    //      2     2
	//     / \   / \
    //    3   4 4   3

	Node* t1 = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL))
	);

	Node* t2 = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL))
	);

	bool identici = TreeAreIdentical(t1, t2);



	//no uguali
	Node* t3 = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 5 }, NULL, NULL))
	);

	Node* t4 = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL))
	);

	identici = TreeAreIdentical(t3, t4);

}
