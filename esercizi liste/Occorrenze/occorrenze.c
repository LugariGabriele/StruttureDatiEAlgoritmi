#include "list.h"

int ListaOccorrenze(const Item* i, const ElemType* e) {

	int occorenze = 0;

	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), &e) == 0) // stesso elem
		{
			occorenze++;
		}

		i = ListGetTail(i);
	}

	return occorenze;
}

int main(void) {


	ElemType* a = 1;
	ElemType* b = 2;
	ElemType* c = 1;
	ElemType* d = 1;

	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	ListWriteStdout(list);

	int res = ListaOccorrenze(list, 1);
}