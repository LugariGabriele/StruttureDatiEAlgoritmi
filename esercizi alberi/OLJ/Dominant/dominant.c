#include "tree.h"

int CountDominant(const Node* t) {

	if (TreeIsEmpty(t))
	{
		return 0;
	}
	

	Node* left = TreeLeft(t);
	Node* right = TreeRight(t);

	int sum = 0;
	if (!TreeIsEmpty(left))
	{
		sum += *TreeGetRootValue(left);
	}

	if (!TreeIsEmpty(right)) 
    {
		sum += *TreeGetRootValue(right);
	}

	int nodi_dominanti = *TreeGetRootValue(t) > sum ? 1 : 0;

	return nodi_dominanti + CountDominant(left) + CountDominant(right);
}

int main(void) {
    // Costruzione dell'albero dell'esempio:
    //          12
    //         /  \
    //        4    21
    //       / \     \
    //      0   2     5
    //     / \       /
    //    7   8     18
    //              /
    //             9

    Node* n7 = TreeCreateRoot(&(ElemType) { 7 }, NULL, NULL);
    Node* n8 = TreeCreateRoot(&(ElemType) { 8 }, NULL, NULL);
    Node* n0 = TreeCreateRoot(&(ElemType) { 0 }, n7, n8);
    Node* n2 = TreeCreateRoot(&(ElemType) { 2 }, NULL, NULL);
    Node* n4 = TreeCreateRoot(&(ElemType) { 4 }, n0, n2);

    Node* n9 = TreeCreateRoot(&(ElemType) { 9 }, NULL, NULL);
    Node* n18 = TreeCreateRoot(&(ElemType) { 18 }, n9, NULL);
    Node* n5 = TreeCreateRoot(&(ElemType) { 5 }, n18, NULL);
    Node* n21 = TreeCreateRoot(&(ElemType) { 21 }, NULL, n5);

    Node* root = TreeCreateRoot(&(ElemType) { 12 }, n4, n21);

    int dominant = CountDominant(root);
    printf("Numero di nodi dominanti: %d\n", dominant);  // Output atteso: 1

    TreeDelete(root);
    return 0;
}