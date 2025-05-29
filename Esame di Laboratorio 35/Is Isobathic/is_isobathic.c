#include "tree.h"
#include <stdbool.h>


bool CheckDepth(const Node* t, int depth, int* leaf_depth) {
	if (t==NULL)
	{
		return true;
	}

	if (TreeIsLeaf(t))
	{
		if (*leaf_depth == -1) {
			*leaf_depth = depth; // prima foglia trovata salvo profondità così controllo per quelle dopo
		}
		else if(depth!= *leaf_depth){ // sono in foglia ma profondità non coincidono
			return false;
		}
		return true;
	}

	return CheckDepth(TreeLeft(t), depth + 1, leaf_depth) && CheckDepth(TreeRight(t), depth + 1, leaf_depth);
}

bool IsIsobathic(const Node* t) {

	int leaf_depth = -1;
	return CheckDepth(t, 0, &leaf_depth);
}
//
//int main(void) {
//	// Creo un albero non isobato:
//   //       1
//   //      / \
//    //     2   3
//	//    /
//	//   4
//
//	ElemType e1 = 1, e2 = 2, e3 = 3, e4 = 4, e5 = 5;
//	Node* leaf4 = TreeCreateRoot(&e4, NULL, NULL);
//	Node* leaf5 = TreeCreateRoot(&e5, NULL, NULL);
//	Node* node2 = TreeCreateRoot(&e2, leaf4, NULL);
//	Node* node3 = TreeCreateRoot(&e3, NULL, leaf5);
//	Node* root1 = TreeCreateRoot(&e1, node2, node3);
//	Node* node2b = TreeCreateRoot(&e2, leaf4, NULL);
//	Node* node3b = TreeCreateRoot(&e3, NULL, NULL);
//	Node* root2 = TreeCreateRoot(&e1, node2b, node3b);
//
//	printf("Albero 2 isobato? %s\n", IsIsobathic(root2) ? "true" : "false");
//}