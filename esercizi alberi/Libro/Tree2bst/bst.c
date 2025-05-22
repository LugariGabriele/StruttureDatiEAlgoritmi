#include "tree.h"


// Inserisce nel BST, ignorando i duplicati
Node* InsertBst(Node* root, const ElemType* e) {
	if (root == NULL) {
		return TreeCreateRoot(e, NULL, NULL);
	}

	int cmp = ElemCompare(e, TreeGetRootValue(root));

	if (cmp < 0) {
		root->left = InsertBst(root->left, e);
	}
	else if (cmp >= 0) {
		root->right = InsertBst(root->right, e);
	}

	return root;
}


void tree2bstRec(const Node* t, const Node** bst) { // esploro albero t e la uso per costruire bst

	if (t == NULL)
	{
		return;
	}

	//in ordine sx radice dx
	tree2bstRec(t->left, bst);
	*bst = InsertBst(*bst, &t->value);
	tree2bstRec(t->right, bst);
}


Node* tree2bst(const Node* t) {

	//dato un albero generico t la funzionde deve visitarlo in ordine	e custruire i suoi elementi sun un nuovo bst
	//ogni elemento del bst deve essere aggiunto secondo l'ordine di esplorazione di t seguendo il criterio che il figlio sx deve essere minore e quello dx >=

	if (TreeIsEmpty(t))
	{
		return TreeCreateEmpty();
	}

	Node* bst = NULL;
	tree2bstRec(t, &bst);

	return bst;
}


int main(void) {


	Node* t = TreeCreateRoot(&(ElemType) { 6 },
		TreeCreateRoot(&(ElemType) { 2 },
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL),
			TreeCreateRoot(&(ElemType) { 8 }, NULL,
				TreeCreateRoot(&(ElemType) { 5 }, NULL, NULL))
		),
		TreeCreateRoot(&(ElemType) { 9 }, NULL,
			TreeCreateRoot(&(ElemType) { 3 }, NULL, NULL))
	);

	printf("Albero originale (in-order):\n");
	TreeWriteStdoutInOrder(t);
	printf("\n");

	Node* bst = tree2bst(t);

	printf("Albero BST risultante (in-order):\n");
	TreeWriteStdoutInOrder(bst);
	printf("\n");

	TreeDelete(t);
	TreeDelete(bst);

	return 0;
}