#include "concatena.h"

Item* Concatena(Item* i1, Item* i2, enum ConcType c) {

	if (i1 == NULL && i2 == NULL)
	{
		return ListCreateEmpty();
	}

	if (c == kCopy) // ritorno lista nuova
	{
		Item* lista_conc = ListCreateEmpty();
		
		Item* tmp = i1;
		while (!ListIsEmpty(tmp)) {
			ElemType *e = ListGetHeadValue(tmp);
			lista_conc = ListInsertBack(lista_conc, e);
			tmp = ListGetTail(tmp);
		}

		// Copia della seconda lista
		tmp = i2;
		while (!ListIsEmpty(tmp)) {
			ElemType *e = ListGetHeadValue(tmp);
			lista_conc = ListInsertBack(lista_conc, e);
			tmp = ListGetTail(tmp);
		}
		return lista_conc;
	}

	else //kNoCopy
	{

		if (i1 == NULL) // prima lista vuota
		{
			return i2;
		}

		//sposto il puntatore alla fine della lista
		Item* tmp = i1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = i2;
		return i1;
	}
}


int main(void) {

	ElemType* a = 1;
	ElemType* b = 2;
	ElemType* c = 3;
	ElemType* d = 4;
	ElemType* e = 5;

	Item* i1 = ListCreateEmpty();
	i1 = ListInsertBack(i1, &a);
	i1 = ListInsertBack(i1, &b);

	Item* i2 = ListCreateEmpty();
	i2 = ListInsertBack(i2, &c);
	i2 = ListInsertBack(i2, &d);
	i2 = ListInsertBack(i2, &e);

	Item* kcopy = Concatena(i1, i2, kCopy);
	ListWriteStdout(kcopy);

	Item* knocopy = Concatena(i1, i2, kNoCopy);
	ListWriteStdout(knocopy);

}
