#include "cycle_len.h"
#include <stdlib.h>


int CycleLength(const Item* i) {

	if (ListIsEmpty(i))
	{
		return 0;
	}

	int count = 0;


	const Item* slow = i;
	const Item* fast = i;

	while (fast != NULL) { // se ciclo non arriva a null

		slow = ListGetTail(slow);
		fast = ListGetTail(ListGetTail(fast));

		
		if (fast == slow) //puntano a ultimo valore prima di tornare indietro
		{
			
			fast = ListGetTail(fast);
			count++;
			while (fast != slow) {
				count++;
				fast = ListGetTail(fast);
			}
			break;
		}
	}

	return count;

}

//
//Item* ListCreateFromVector(const ElemType* e, int e_size) {
//	Item* n = ListCreateEmpty();
//	for (int i = 0; i < e_size; ++i) {
//		n = ListInsertBack(n, &e[i]);
//	}
//	return n;
//}
//
//int main(void) {
//	ElemType e1[] = { 1, 2, 3,4 };
//	ElemType e2[] = { 4, 5, 6 };
//	ElemType e3[] = { 7, 8, 9 };
//	Item* list_1 = ListCreateFromVector(e1, sizeof(e1) / sizeof(ElemType));
//	Item* list_2 = ListCreateFromVector(e2, sizeof(e2) / sizeof(ElemType));
//	Item* list_3 = ListCreateFromVector(e3, sizeof(e3) / sizeof(ElemType));
//
//	Item * l2 = list_1;
//	Item* l1 = list_1;
//	while (l1->next != NULL) {
//
//		l1 = ListGetTail(l1);
//	}
//
//	l1->next = l2;
//	
//	int res = CycleLength(list_1);
//
//	
//
//		return 0;
//}