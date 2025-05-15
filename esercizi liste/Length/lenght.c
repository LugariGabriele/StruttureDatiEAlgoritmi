#include "list.h"


int ListLengthRec(const Item* i, int count) {

	if (i->next == NULL)
	{
		return count;
	}

	return ListLengthRec(ListGetTail(i), count +1 ); 
}

int ListLength(const Item* i) {

	if (ListIsEmpty(i))
	{
		return 0;
	}

	return ListLengthRec(i, 1);
}

int ListLengthIter(const Item* i) {

	if (ListIsEmpty(i))
	{
		return 0;
	}

	int count = 0;

	while (!ListIsEmpty(i)) {

		

		count++;
		i = ListGetTail(i);
	}

	return count;
}


int main(void) {

	ElemType a = 1;
	ElemType b = 2;
	ElemType c = 3;

	Item* list = ListCreateEmpty();

	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);

	ListWriteStdout(list);
	int res_iter = ListLengthIter(list);
	int res_Rec = ListLength(list);
}