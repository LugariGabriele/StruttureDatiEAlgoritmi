#include "tree.h"

const ElemType* BstTreeMax(const Node* n) {

	// l'elemento più alto è quello piu a dx del sottoalbero dx

	//per minimizzare numero accessi a nodi vado direttamente lì

	if (TreeIsEmpty(n)) return NULL;

	const Node* curr = n;

	while (!TreeIsEmpty(TreeRight(curr))) { // sposto puntatore all' ultimo elemento
		curr = TreeRight(curr);
	}

	return TreeGetRootValue(curr);  //O(n) n è altezza albero, se albero è bilanciato O(log n)
}

const ElemType* TreeMax(const Node* n) {

	if (TreeIsEmpty(n)) return NULL;

	const ElemType* max_val = TreeGetRootValue(n);

	const ElemType* left_max = TreeMax(TreeLeft(n));

	if (left_max != NULL && ElemCompare(left_max, max_val) > 0) // left più grande 
	{
		max_val = left_max;
	}

	const ElemType* right_max = TreeMax(TreeRight(n));
	if (right_max != NULL && ElemCompare(right_max, max_val) > 0) {
		max_val = right_max;
	}

	return max_val; //O(n) vista completa 
}


int main(void) {


    // Costruisco un BST
    //        10
    //       /  \
    //      5    15
    //          /  \
    //         12   20

    Node* bst = TreeCreateRoot(&(ElemType) { 10 },
        TreeCreateRoot(&(ElemType) { 5 }, NULL, NULL),
        TreeCreateRoot(&(ElemType) { 15 },
            TreeCreateRoot(&(ElemType) { 12 }, NULL, NULL),
            TreeCreateRoot(&(ElemType) { 20 }, NULL, NULL)
        )
    );

    // Costruisco un albero NON BST
    //        10
    //       /  \
    //     30    20
    //     /
    //    50

    Node* non_bst = TreeCreateRoot(&(ElemType) { 10 },
        TreeCreateRoot(&(ElemType) { 30 },
            TreeCreateRoot(&(ElemType) { 50 }, NULL, NULL),
            NULL
        ),
        TreeCreateRoot(&(ElemType) { 20 }, NULL, NULL)
    );

    // Test BST
    const ElemType* max_bst = BstTreeMax(bst);
    printf("Massimo in BST: ");
    if (max_bst != NULL) ElemWriteStdout(max_bst);
    else printf("NULL");
    printf("\n");

    // Test generico
    const ElemType* max_non_bst = TreeMax(non_bst);
    printf("Massimo in albero generico: ");
    if (max_non_bst != NULL) ElemWriteStdout(max_non_bst);
    else printf("NULL");
    printf("\n");


}