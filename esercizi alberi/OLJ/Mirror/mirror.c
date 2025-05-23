#include "tree.h"
#include <stdbool.h>

bool isMirror(const Node* a, const Node* b) {

	if (a == NULL && b == NULL) return true; // se entrambi contemporaneamente null allora è bilanciato(essenziale per essere simmetrico)

	if (a == NULL || b == NULL) return false; // se arrivato qua non bilanciato

	return ElemCompare(&a->value, &b->value) == 0 && isMirror(a->left, b->right) && isMirror(a->right, b->left);
	//controlla prima tutto sx e dx e poi il contrario
}


bool TreeIsMirror(const Node* t) {

	if (t == NULL)
	{
		return  true;
	}

	return isMirror(t->left, t->right);
}


//
//int main(void) {
//
//	// Albero simmetrico:
//   //         1
//   //       /   \
//    //      2     2
//	//     / \   / \
//    //    3   4 4   3
//
//	Node* symmetric = TreeCreateRoot(&(ElemType) { 1 },
//		TreeCreateRoot(&(ElemType) { 2 },
//			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
//			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)),
//		TreeCreateRoot(&(ElemType) { 2 },
//			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL),
//			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL))
//	);
//
//
//	// Albero non simmetrico:
//	//         1
//	//       /   \
//	//      2     2
//	//        \     \
//	 //        3     3
//
//	Node* non_symmetric = TreeCreateRoot(&(ElemType) { 1 },
//		TreeCreateRoot(&(ElemType) { 2 },
//			NULL,
//			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL)),
//		TreeCreateRoot(&(ElemType) { 2 },
//			NULL,
//			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL))
//	);
//
//	printf("Albero 1 %s simmetrico.\n", TreeIsMirror(symmetric) ? "è" : "non è");
//	printf("Albero 2 %s simmetrico.\n", TreeIsMirror(non_symmetric) ? "è" : "non è");
//
//	TreeDelete(symmetric);
//	TreeDelete(non_symmetric);
//}