#include "tree.h"


Node* RemoveLeavesRec(Node* t1) {
	
	if (TreeIsEmpty(t1)) {
		return NULL;
	}

	if (TreeIsLeaf(t1))
	{
		TreeDelete(t1);
		return NULL; //assegno null a nodo così parent dopo pnta a null
	}


	t1->left = RemoveLeavesRec(TreeLeft(t1));
	t1->right = RemoveLeavesRec(TreeRight(t1));

	return t1;
}

Node* RemoveLeaves(Node* t) {

	return RemoveLeavesRec(t);
}

//
//int main(void) {
//
//
//	Node* t = TreeCreateEmpty();
//
//	ElemType a = 3, b = 2, c = 1, d = 5;
//	t = TreeCreateRoot(&a, NULL, NULL);
//
//	TreeWriteStdoutInOrder(t);
//	t = RemoveLeaves(t);
//	TreeWriteStdoutInOrder(t);
//
//
//}
