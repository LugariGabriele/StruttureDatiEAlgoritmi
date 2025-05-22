#include "tree.h"


void CountNodesRec(const Node* t, int* intern, int* external) {

	if (t==NULL) // perevitare che conti foglie in più quando ho nodo con solo 1 figlio
	{
		return;
	}

	if (TreeIsLeaf(t))
	{
		(*external)++;
		return;
	}
	else
	{
		(*intern)++;
	}
	CountNodesRec(t->left, intern, external);
	CountNodesRec(t->right, intern, external);
}

void TreeCountNodes(const Node* t, int* intern, int* external) {
	if (TreeIsEmpty(t))
	{
		*intern = 0;
		*external = 0;
		return;
	}

	*intern = 0;
	*external = 0;
	CountNodesRec(t, intern, external);
}


int main(void) {

	/*
			1
		   / \
		  2   3
			   \
			     4
		
       2 interni e 2 foglie
	*/

	Node* t = TreeCreateRoot(&(ElemType) { 1 },
		TreeCreateRoot(&(ElemType) { 2 }, NULL, NULL),
		TreeCreateRoot(&(ElemType) { 3 }, NULL,
			TreeCreateRoot(&(ElemType) { 4 }, NULL, NULL))

	);

	int intern, external;
	TreeCountNodes(t, &intern, &external);

	printf("Interni: %d, Esterni: %d\n", intern, external); 
}