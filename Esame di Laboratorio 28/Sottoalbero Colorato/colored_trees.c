#include "tree.h"
#include <stdbool.h>

bool IsAllSameColor(const Node* t, ElemType color) {

	if (TreeIsEmpty(t))
	{
		return true;
	}
	
	if (ElemCompare(&t->value,color)!=0)
	{
		return false;
	}

	return IsAllSameColor(t->left, color) && IsAllSameColor(t->right, color);

}

int CountNodes(const Node* t) {
	if (t == NULL) return 0;
	return 1 + CountNodes(t->left) + CountNodes(t->right);
}

int TreeHeight(const Node* t) {

	if (TreeIsEmpty(t))
	{
		return 0;
	}

	int lh = TreeHeight(t->left);
	int rh = TreeHeight(t->right);

	return 1 + (lh < rh) ? rh : lh;
}

const Node* BiggestColoredTree(const Node* t) {

	if (TreeIsEmpty(t))
	{
		return NULL;
	}

	const Node* left_best = BiggestColoredTree(t->left);
	const Node* right_best = BiggestColoredTree(t->right);
	const Node* best = NULL;

	if (IsAllSameColor(t,&t->value))
	{
		best = t;
	}

	//confronto con sx
	if (best==NULL || (left_best !=NULL && CountNodes(left_best) > CountNodes(best))
		|| (left_best != NULL && CountNodes(left_best) == CountNodes(best) &&
			TreeHeight(left_best) > TreeHeight(best)))
	{
		best = left_best;
	}

	// confronto con il destro
	if (best == NULL ||
		(right_best != NULL && CountNodes(right_best) > CountNodes(best)) ||
		(right_best != NULL && CountNodes(right_best) == CountNodes(best) &&
			TreeHeight(right_best) > TreeHeight(best))) 
	{
		best = right_best;
	}

	return best;
}

int main(void) {
	// Costruzione dell'albero:
	//        b
	//       / \
    //      v   r
	//     /     \
    //    v       r
	//     \     /
	//      v   r

	ElemType b = 'b', v = 'v', r = 'r';

	Node* v3 = TreeCreateRoot(&v, NULL, NULL);
	Node* v2 = TreeCreateRoot(&v, NULL, v3);
	Node* v1 = TreeCreateRoot(&v, v2, NULL);

	Node* r3 = TreeCreateRoot(&r, NULL, NULL);
	Node* r2 = TreeCreateRoot(&r, r3, NULL);
	Node* r1 = TreeCreateRoot(&r, NULL, r2);

	Node* root = TreeCreateRoot(&b, v1, r1);

	const Node* res = BiggestColoredTree(root);

	printf("Nodo radice del sottoalbero migliore: '%c'\n", *TreeGetRootValue(res));

	TreeDelete(root);
	return 0;
}
