#include "tree.h"

static Node* TreeCopy(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	n->left = TreeCopy(TreeLeft(t));
	n->right = TreeCopy(TreeRight(t));
	return n;
}

Node* MergeTree(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return TreeCreateEmpty();
	}

	if (TreeIsEmpty(t1)) // copia tutto albero dal nodo t2 in poi
	{
		return TreeCopy(t2);
	}

	if (TreeIsEmpty(t2))	// copia tutto albero dal nodo t in poi

	{
		return TreeCopy(t1);
	}


	ElemType sum = *TreeGetRootValue(t1) + *TreeGetRootValue(t2); // sommo radici
	Node* new_root = TreeCreateRoot(&sum, NULL, NULL);

	new_root->left = MergeTree(TreeLeft(t1), TreeLeft(t2));
	new_root->right = MergeTree(TreeRight(t1), TreeRight(t2));


	return new_root;
}

//
//int main(void) {
//    // Costruzione albero t1
//    //         -2
//    //        /  \
//    //       5    1
//    //      / \     \
//    //     8   2     1
//    //          \
//    //           4
//
//    Node* t1 =
//        TreeCreateRoot(&(ElemType) { -2 },
//            TreeCreateRoot(&(ElemType) { 5 },
//                TreeCreateRoot(&(ElemType) { 8 }, NULL, NULL),
//                TreeCreateRoot(&(ElemType) { 2 },
//                    NULL,
//                    TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL))),
//            TreeCreateRoot(&(ElemType) { 1 },
//                NULL,
//                TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL)));
//
//    // Costruzione albero t2
//    //         -3
//    //        /  \
//    //      10    1
//    //            / \
//    //           9  -1
//
//    Node* t2 =
//        TreeCreateRoot(&(ElemType) { -3 },
//            TreeCreateRoot(&(ElemType) { 10 }, NULL, NULL),
//            TreeCreateRoot(&(ElemType) { 1 },
//                TreeCreateRoot(&(ElemType) { 9 }, NULL, NULL),
//                TreeCreateRoot(&(ElemType) { -1 }, NULL, NULL)));
//
//    // Merge degli alberi
//    Node* merged = MergeTree(t1, t2);
//
//    // Stampa dell'albero in pre-order (root, left, right)
//    printf("Albero risultato (pre-order): ");
//    TreeWriteStdoutPreOrder(merged);
//    printf("\n");
//
//    // Pulizia memoria
//    TreeDelete(t1);
//    TreeDelete(t2);
//    TreeDelete(merged);
//
//    return 0;
//}