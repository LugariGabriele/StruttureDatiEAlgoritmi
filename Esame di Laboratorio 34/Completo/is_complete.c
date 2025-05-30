#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

int CountNode(Node* t) {
	if (TreeIsEmpty(t))
	{
		return 0;
	}

	return 1 + CountNode(t->left) + CountNode(t->right);
}

bool IsCompleteRec(const Node* t, int index, int nodeCount) {

	//idea è che se io ho un figlio in una posizione (array immaginario) che è pari o maggiore
	//al numero di nodi allora ho un buco in mezzo da qualche parte (indice parte da 0 se giusto arriva max a n-1)

	if (t==NULL)
	{
		return true;
	}

	if (index>= nodeCount)
	{
		return false;
	}

	bool leftOk = IsCompleteRec(t->left, 2 * index + 1, nodeCount); //controllo figlio sx
	bool rightOk = IsCompleteRec(t->right, 2 * index + 2, nodeCount); //controllo figlio dx

	return leftOk && rightOk;
}

bool IsComplete(const Node* t) {

	if (t==NULL)
	{
		return true;
	}

	int nodecount = CountNode(t);
	return IsCompleteRec(t, 0, nodecount);
}

//int main(void) {
//	ElemType v1 = 1, v2 = 2, v3 = 3, v4 = 4;
//
//	Node* n4 = TreeCreateRoot(&v4, NULL, NULL);
//	Node* n2 = TreeCreateRoot(&v2, NULL, n4);
//	Node* n3 = TreeCreateRoot(&v3, NULL, NULL);
//	Node* n1 = TreeCreateRoot(&v1, n2, n3);  // Radice
//
//	// Verifica se l'albero è completo
//	if (IsComplete(n1)) {
//		printf("L'albero è completo.\n");
//	}
//	else {
//		printf("L'albero NON è completo.\n");
//	}
//
//	// Libera la memoria dell'albero
//	TreeDelete(n1);
//}