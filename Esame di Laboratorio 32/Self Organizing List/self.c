#include "self.h"




Item* SelfOrganizingFind(Item* i, const ElemType* e) {

	if (ListIsEmpty(i))
	{
		return i;
	}

	if (ElemCompare(e, ListGetHeadValue(i))==0)
	{
		return i;
	}

	Item* current = i;
	Item* parent = NULL;

	//sposto puntatori fino ad elemento da spostare (current sul nodo da eliminare e parent su quello prima)
	while (!ListIsEmpty(current)) {
		
		if (ElemCompare(e, ListGetHeadValue(current)) == 0) {
			break;
		}
		parent = current;
		current = ListGetTail(current);
	}

	//caso in cui elemenento trovato non esite
	if (current ==NULL)
	{
		return i;
	}
	
	parent->next = current->next; // attacco saltando nodo da eliminare
	current->next = i;
	i = current;

	return i;
}


//
//int main(void) {
//
//	ElemType a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
//	Item* l = ListCreateEmpty();
//
//	l = ListInsertBack(l, &a);
//	l = ListInsertBack(l, &b);
//	l = ListInsertBack(l, &c);
//	l = ListInsertBack(l, &d);
//	l = ListInsertBack(l, &e);
//	l = ListInsertBack(l, &f);
//
//	ListWriteStdout(l);
//
//	ElemType find = 2;
//	l = SelfOrganizingFind(l, &find);
//	ListWriteStdout(l);
//}
