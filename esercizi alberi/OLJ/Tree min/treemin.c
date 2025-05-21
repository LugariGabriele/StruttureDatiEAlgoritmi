#include "tree.h"

const ElemType* BstTreeMin(const Node* n) {

	//elemento più piccolo è quello più a sx del sottoalbero sx

	if (TreeIsEmpty(n)) return NULL;

	const Node* curr = n;

	while (!TreeIsEmpty(TreeLeft(curr))) {
		curr = TreeLeft(curr);
	}

	return TreeGetRootValue(curr);

}

const ElemType* TreeMinHelper(const Node* n, int depth, const ElemType** min_val, int* max_depth) {

	//uso **elemType così aggiorno il puntatore direttamente orginale (se metto * min_val cambio il valore ma non l'indirizzo)

	if (TreeIsEmpty(n)) return;

	const ElemType* curr = TreeGetRootValue(n);

	if (*min_val == NULL || ElemCompare(curr, *min_val) < 0) {
		*min_val = curr;
		*max_depth = depth;
	}
	else if (ElemCompare(curr, *min_val) == 0 && depth > *max_depth) {
		*min_val = curr;
		*max_depth = depth;
	}

	// Visita prima il sottoalbero DESTRO per dare precedenza ai nodi più a destra
	TreeMinHelper(TreeRight(n), depth + 1, min_val, max_depth);
	TreeMinHelper(TreeLeft(n), depth + 1, min_val, max_depth);
}

const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) return NULL;

	const ElemType* min_val = NULL;
	int max_depth = -1;
	TreeMinHelper(n, 0, &min_val, &max_depth);
	return min_val;
}


int main(void) {

	// Costruiamo un albero NON BST per testare TreeMin()
		//         10
		//        /  \
	    //       4    7
		//      / \    \
	    //     1   6    1

	Node* non_bst = TreeCreateRoot(&(ElemType) { 10 },
		TreeCreateRoot(&(ElemType) { 4 },
			TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 6 }, NULL, NULL)),
		TreeCreateRoot(&(ElemType) { 7 },
			NULL,
			TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL))
	);


	// Costruiamo un BST per testare BstTreeMin()
   //         8
   //        / \
    //       3   10
	//      /
	//     1

	Node* bst = TreeCreateRoot(&(ElemType) { 8 },
		TreeCreateRoot(&(ElemType) { 3 },
			TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL),
			NULL),
		TreeCreateRoot(&(ElemType) { 10 }, NULL, NULL)
	);

	// Trova minimo nell'albero non BST
	const ElemType* min1 = TreeMin(non_bst);
	if (min1 != NULL) {
		printf("Minimo nell'albero non BST: ");
		ElemWriteStdout(min1);
		printf("\n");
	}
	else {
		printf("L'albero non BST è vuoto.\n");
	}

	// Trova minimo nel BST
	const ElemType* min2 = BstTreeMin(bst);
	if (min2 != NULL) {
		printf("Minimo nel BST: ");
		ElemWriteStdout(min2);
		printf("\n");
	}
	else {
		printf("Il BST è vuoto.\n");
	}
}
