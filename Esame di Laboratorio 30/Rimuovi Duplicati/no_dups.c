#include "no_dups.h"
#include <stdbool.h>

Item* RemoveDuplicates(const Item* i) {

	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}

	Item* res = ListCreateEmpty();


	Item* curr = i;

	while (!ListIsEmpty(curr)) {

		bool dup = false;
		const ElemType* val_i = ListGetHeadValue(curr);
		Item* tmp = res;

		//scorro res
		while (!ListIsEmpty(tmp)) {

			ElemType *val_res = ListGetHeadValue(tmp);

			if (ElemCompare(val_i, val_res) == 0)
			{
				dup = true;
				break;
			}
			tmp = ListGetTail(tmp);
		}

		// Se non è duplicato, aggiungilo in coda a res
		if (!dup) {
			res = ListInsertBack(res, val_i);
		}

		curr = ListGetTail(curr);
		
	}

	return res;
}
//
//int main(void) {
//
//
//	ElemType a = 1, b = 2, c = 3, d = 2, e = 1;
//
//
//	Item* l = ListCreateEmpty();
//	l = ListInsertBack(l, &a);
//	l = ListInsertBack(l, &b);
//	l = ListInsertBack(l, &c);
//	l = ListInsertBack(l, &d);
//	l = ListInsertBack(l, &e);
//
//	ListWriteStdout(l);
//
//	Item* res = RemoveDuplicates(l);
//
//	ListWriteStdout(res);
//}