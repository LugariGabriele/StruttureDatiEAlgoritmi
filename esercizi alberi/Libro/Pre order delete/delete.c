#include "tree.h"
#include <stdlib.h>

void TreePreOrderDelete(Node* t) {

	if (t == NULL)
	{
		return;
	}
	//devo eliminare la memoria dell' albero attraversandolo in preordine e stampando i nodi visitati --> preordine (radice -sx -dx)
	ElemWriteStdout(TreeGetRootValue(t));
	printf(" ");
	
	TreePreOrderDelete(t->left);
	TreePreOrderDelete(t->right);
	
	free(t); // dealloco intero nodo 
}



int main(void) {
	/*
			1
		2		5
	  3	  4	  6	   7

	*/



	Node* t = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL)
		),
		TreeCreateRoot(&(ElemType) { 5 },
			TreeCreateRoot(&(ElemType) { 6 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 7 }, NULL, NULL)
		)
	);

	 TreePreOrderDelete(t);
}