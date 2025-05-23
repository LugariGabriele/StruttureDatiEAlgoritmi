#include "tree.h"


Node* BstInsert(const ElemType* e, Node* n) {

	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}

	Node* curr = n;
	Node* parent = NULL;


	while (!TreeIsEmpty(curr)) { // mando puntatore curr alla root padre dove deve essere aggiunto e
		parent = curr;

		if (ElemCompare(e, TreeGetRootValue(curr)) <= 0) // se elem è minore di root  e-root<=0 --> e <=root
		{
			// elem deve andare a sx
			curr = TreeLeft(curr);
		}
		else
		{
			curr = TreeRight(curr);
		}
	}

	if (ElemCompare(e, TreeGetRootValue(parent)) <= 0)
	{
		parent->left = TreeCreateRoot(e, NULL, NULL);
	}

	else
	{
		parent->right = TreeCreateRoot(e, NULL, NULL);
	}

	return n;
}



Node* BstInsertRec(const ElemType* e, Node* n) {

	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}

	if (ElemCompare(e, TreeGetRootValue(n)) <= 0)
	{
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else
	{
		n->right = BstInsertRec(e, TreeRight(n));
	}
	return n;
}

//
//int main(void) {
//
//	Node* iterative_bst = TreeCreateEmpty();
//	Node* recursive_bst = TreeCreateEmpty();
//
//	ElemType values[] = { 4, 3, 7, 1, 5, 8, 2 };
//	int n = sizeof(values) / sizeof(ElemType);
//
//	for (int i = 0; i < n; ++i) {
//		iterative_bst = BstInsert(&values[i], iterative_bst);
//		recursive_bst = BstInsertRec(&values[i], recursive_bst);
//	}
//
//	printf("BST iterativo (in-order): ");
//	TreeWriteStdoutInOrder(iterative_bst);
//	printf("\n");
//
//	printf("BST ricorsivo (in-order): ");
//	TreeWriteStdoutInOrder(recursive_bst);
//	printf("\n");
//
//	TreeDelete(iterative_bst);
//	TreeDelete(recursive_bst);
//
//
