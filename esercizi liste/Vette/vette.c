#include "list.h"
#include <stdbool.h>

int ContaVette(const Item* i) {
	if (ListIsEmpty(i))
	{
		return 0;
	}


	//vetta quando tutti i num dopo quell' elem sono minori di elem
	int vette = 0; // ultimo elem è sempre vetta

	Item* tmp1 = i;
	while (!ListIsEmpty(tmp1)) {

		ElemType* e1 = ListGetHeadValue(tmp1);
		bool vetta = true;

		Item* tmp2 = ListGetTail(tmp1); // elem sucessivi a e

		while (!ListIsEmpty(tmp2)) {

			ElemType* e2 = ListGetHeadValue(tmp2);

			if (ElemCompare(e1, e2) <= 0) // elem che non va bene 
			{
				vetta = false;
				break;
			}
			tmp2 = ListGetTail(tmp2);
		}

		if (vetta)
		{
			vette++;
		}

		tmp1 = ListGetTail(tmp1);
	}

	return vette;
}


int main(void) {

	ElemType* a = 7;
	ElemType* b = 2;
	ElemType* c = 5;
	ElemType* d = 5;
	ElemType* e = 4;


	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);
	list = ListInsertBack(list, &e);


	ListWriteStdout(list);

	int num = ContaVette(list);

	printf("%d", num);

}