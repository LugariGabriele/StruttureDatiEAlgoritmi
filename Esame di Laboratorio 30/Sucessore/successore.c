#include "tree.h"


void SucessoreRec(const Node* t, const Node* n, const Node** best) {
	if (t == NULL)
	{
		return;
	}

	if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(n)) > 0)
	{
		if (*best == NULL || ElemCompare(TreeGetRootValue(t), TreeGetRootValue(*best)) < 0) {
			*best = t;
		}
	}

	SucessoreRec(TreeLeft(t), n, best);
	SucessoreRec(TreeRight(t), n, best);

}

const Node* Successore(const Node* t, const Node* n) {

	if (t == NULL || n == NULL)
	{
		return NULL;
	}

	const Node* best = NULL;

	SucessoreRec(t, n, &best);

	return best;
}


//
//int main(void) {
//
//
//	ElemType a = 3, b = 2, c = 5, d = 1;
//	Node* tree = TreeCreateRoot(&a,
//		TreeCreateRoot(&b,
//			TreeCreateRoot(&d, NULL, NULL)
//			, NULL),
//		TreeCreateRoot(&c, NULL, NULL)
//	);//radice
//
//	Node* n = TreeCreateRoot(&b, NULL, NULL);
//
//	const Node* min = Successore(tree, n);
//}