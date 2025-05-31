#include "tree.h"
#include <stdbool.h>


bool BSTRec(Node* t) {

	if (TreeIsEmpty(t))
	{
		return true;
	}

	const ElemType* val = TreeGetRootValue(t);
	bool leftOk = true;
	bool rightOk = true;

	if (TreeLeft(t) != NULL)
	{
		const ElemType* left_value = TreeGetRootValue(TreeLeft(t));
		leftOk = ElemCompare(left_value, val) <= 0 && BSTRec(TreeLeft(t));

	}

	if (TreeRight(t) != NULL) {
		const ElemType* right_value = TreeGetRootValue(TreeRight(t));
		rightOk = ElemCompare(right_value, val) > 0 && BSTRec(TreeRight(t));
	}


	return leftOk && rightOk;
}

bool IsBST(Node* t) {
	if (TreeIsEmpty(t))
	{
		return true;
	}

	return BSTRec(t);
}
//
//int main(void) {
//	// Costruisco un albero valido BST:
//	//        5
//	//       / \
//    //      3   7
//	//     / \   \
//    //    2   4   8
//
//	ElemType e5 = 5, e3 = 3, e7 = 7, e2 = 2, e4 = 4, e8 = 8;
//
//	Node* n2 = TreeCreateRoot(&e2, TreeCreateEmpty(), TreeCreateEmpty());
//	Node* n4 = TreeCreateRoot(&e4, TreeCreateEmpty(), TreeCreateEmpty());
//	Node* n3 = TreeCreateRoot(&e3, n2, n4);
//	Node* n8 = TreeCreateRoot(&e8, TreeCreateEmpty(), TreeCreateEmpty());
//	Node* n7 = TreeCreateRoot(&e7, TreeCreateEmpty(), n8);
//	Node* root = TreeCreateRoot(&e5, n3, n7);
//
//	if (IsBST(root)) {
//		printf("L'albero è un BST valido.\n");
//	}
//	else {
//		printf("L'albero NON è un BST.\n");
//	}
//
//	TreeDelete(root); // libera memoria
//
//	return 0;
//}