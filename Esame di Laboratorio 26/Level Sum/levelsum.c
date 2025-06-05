#include "tree.h"


void LevelSumRec(const Node* t, size_t level, int level_curr, int* sum) {

	if (TreeIsEmpty(t))
	{
		return;
	}

	if ((int)level == level_curr && TreeGetRootValue(t)!= NULL)
	{
		*sum += *TreeGetRootValue(t);
	}

	

	LevelSumRec(t->left, level, level_curr + 1, sum);
	LevelSumRec(t->right, level, level_curr + 1, sum);
}

int LevelSum(const Node* t, size_t level) {

	if (TreeIsEmpty(t))
	{
		return 0;
	}

	if (level == 0)
	{
		return *TreeGetRootValue(t);
	}

	int sum = 0;
	LevelSumRec(t, level, 0, &sum);

	return sum;
}

int main(void) {
	
	ElemType e0 = -2, e1 = 5, e2 = 1, e3 = 8, e4 = 2, e5 = 1, e6 = -9, e7 = 11;

	Node* n11 = TreeCreateRoot(&e7, NULL, NULL);        // 11
	Node* n10 = TreeCreateRoot(&e6, NULL, NULL);        // -9
	Node* n9 = TreeCreateRoot(&e5, n11, NULL);          // 1 → 11
	Node* n8 = TreeCreateRoot(&e4, NULL, NULL);         // 2
	Node* n7 = TreeCreateRoot(&e3, NULL, n10);          // 8 → -9
	Node* n6 = TreeCreateRoot(&e2, NULL, n9);           // 1 → 1(→11)
	Node* n5 = TreeCreateRoot(&e1, n7, n8);             // 5 → 8,2
	Node* root = TreeCreateRoot(&e0, n5, n6);

	int somma = LevelSum(root, 3);
}