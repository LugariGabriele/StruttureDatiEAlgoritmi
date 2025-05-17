#include "list.h"

Item* Filter(Item* i, ElemType n) {
	//devo eliminare tutti elem>=n


	Item* res = ListCreateEmpty();
	Item* tmp = i;
	while (tmp != NULL) {
		ElemType *e = ListGetHeadValue(tmp);
		if (ElemCompare(e, &n) >= 0)  // >= n
		{
			tmp = ListGetTail(tmp);
			continue;
		}

		res = ListInsertBack(res, e);
		tmp = ListGetTail(tmp);

	}

	return res;
}

int main(void) {


	ElemType* a = 1;
	ElemType* b = 2;
	ElemType* c = 3;
	ElemType* d = 1;

	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	ListWriteStdout(list);

	list = Filter(list, 2);
	ListWriteStdout(list);
}
