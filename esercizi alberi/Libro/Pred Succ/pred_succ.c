#include "tree.h"

/*
il predecessore in ordine in un BST � definito come il nodo che precede n nelle vista in ordine 
e il sucessore come quello che lo segue nella vista

le funzioni devono ritornare il puntatore al predecessore/ sucessore del nodo chiavee
se e non ha predecessore o sucesssore ritorna null
si assuma chenon ci siano chiavi duplicate e che e sia sempre presente
*/


Node* Predecessore(const Node* t, const ElemType* e) {

	//predecessore � quindi nodo pi� a dx del sottoalbero sx di e 

	Node* curr = t;
	Node *predecessore = NULL;

	while (curr != NULL) {

		// vado tutto sx fino a quando non trovo punto in cui diventa minore e e guardo num pi� alto possibile
		if (ElemCompare(e,&curr->value) > 0) // e > curr->value
		{
			predecessore = curr;
			curr = curr->right; // cerca qualcosa vicino ad e pi� grande
		}
		else
		{
			curr = curr->left; // cerco elem
		}
	}
	return predecessore;

}


Node* Sucessore(const Node* t, const ElemType* e) {

	Node* curr = t;
	Node* sucessore = NULL;

	//sucessore � quindi nodo pi� sx del sottolbero dx di e 
	while (curr != NULL) {

		if (ElemCompare(e, &curr->value) < 0) // e < curr->value
		{
			sucessore = curr;
			curr = curr->left; // cerca qualcosa vicino ad e pi� piccolo
		}
		else
		{
			curr = curr->right; // cerco elem
		}
	}
	return sucessore;
}