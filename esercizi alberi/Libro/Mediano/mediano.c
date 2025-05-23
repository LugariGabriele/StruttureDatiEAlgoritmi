#include "tree.h"


int ContaNodi(const Node* t) {

	if (t == NULL)
	{
		return 0;
	}

	return 1 + ContaNodi(t->left) + ContaNodi(t->right);
}

void Trova(Node* t, int* count, int target1, int target2, ElemType** res1, ElemType** res2) {
	/*
	cout serve per tenere traccia della posizione in "array" immaginario di lettura
	target 1 e 2 sono le posizioni da cercare cioè quelli centrali
	res1 e res2 sono puntatori per salvare elemento della posizione target
	*/


	//SE FACCIO VISTA IN ORDER(SX- RADICE - DX) IN BST è AUTOMATICAMENTE CONTROLLO DI ELEME CRESCIENTE
	if (t==NULL)
	{
		return;
	}

	Trova(t->left, count, target1, target2, res1, res2);
	if (*count== target1)
	{
		*res1 = TreeGetRootValue(t);
	}
	if (*count == target2) {
		*res2 = TreeGetRootValue(t);
		return; // possiamo uscire dopo aver trovato entrambi
	}

	(*count)++;
	Trova(t->right, count, target1, target2, res1, res2);
}


double Mediano(const Node* t) {

	/*

	funzione pernde un albero BST di int e deve ritornare il mediano
	il valore  mediano deve essere trovato sfruttando le proprietà del BST senza uso strutture dati nuove
	in una distribuzione ordinata di n elementi il valore mediano è l'unità che occupa
	la posizione centrale se n è dispari, la media delle due unità che occupano il centro se n pari

	*/

	int num_nodi = ContaNodi(t); // n


	if (TreeIsEmpty(t))
	{
		return 0;
	}


	int count = 0;
	const ElemType* val1 = NULL;
	const ElemType* val2 = NULL;



	if (num_nodi %2 ==1) // dispari
	{
		// 7-1/2 =3 == 7/2=3
		int mid = num_nodi / 2;
		Trova(t, &count, mid, mid, &val1, &val2);

		if (val1 == NULL) return 0.0;
		return *val2; // val2 e 1 coincidono se dispari
	}

	else //pari
	{
		//8-1/2=3 != 8/2=4
		int mid1 = num_nodi / 2 - 1;
		int mid2 = num_nodi / 2;

		Trova(t, &count, mid1, mid2, &val1, &val2);
		if (val1 == NULL || val2 == NULL) return 0.0;
		return (*val1 + *val2) / 2.0;
	}
}

int main(void) {

	// Costruisco un BST con valori ordinati in-order: [1, 3, 4, 5, 7]
	Node* bst = TreeCreateRoot(&(ElemType) { 4 },
		TreeCreateRoot(&(ElemType) { 3 },
			TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL),
			NULL),
		TreeCreateRoot(&(ElemType) { 7 },
			TreeCreateRoot(&(ElemType) { 5 }, NULL, NULL),
			NULL)
	);

	double median = Mediano(bst);
	printf("Mediano dell'albero: %f\n", median);

	TreeDelete(bst);
	return 0;

}