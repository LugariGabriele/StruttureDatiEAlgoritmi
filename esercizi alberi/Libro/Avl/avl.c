#include "tree.h"
#include <stdbool.h>
#include <math.h>


int TreeHeight(const Node* t) {
	
	if (t==NULL)
	{
		return 0;
	}

	int left = TreeHeight(t->left);
	int right = TreeHeight(t->right);

	return 1 + (left > right ? left : right); // trova altezza massima dato un nodo
}


int GetBalanceCoeff(const Node* n) {
	//il coefficente di un nodo n si calcola facendo differenza tra aletezza tra
	// sottoalbero sx - sottoalbero dx

	if (n== NULL)
	{
		return 0;
	}

	int left_height = TreeHeight(n->left);
	int right_height = TreeHeight(n->right);

	return left_height - right_height;
}


bool TreeIsBalanced(const Node* t) {

	//un albero è bilanciato quando per ogni nodo la differenza di altezza dei suoi figli(coefficente)
	// differisce di al massimo uno

	if (TreeIsEmpty(t))
	{
		return true;
	}

	int coeff = GetBalanceCoeff(t);
	if (abs(coeff)>1)
	{
		return false;
	}

	bool balance_left = TreeIsBalanced(t->left);
	bool balance_right = TreeIsBalanced(t->right);

	return balance_left && balance_right;

}

int main(void) {
	
	Node* t = TreeCreateRoot(&(ElemType) { 2 },
		TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL),
		TreeCreateRoot(&(ElemType) { 4 }, NULL,
			TreeCreateRoot(&(ElemType) { 5 }, NULL,
				TreeCreateRoot(&(ElemType) { 6 }, NULL, NULL))
		)
	);

	bool balance = TreeIsBalanced(t);
}