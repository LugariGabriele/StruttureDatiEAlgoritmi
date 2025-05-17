#include "list.h"

Item* ConcatenaN(Item** v, size_t v_size) {

	if (v_size == 0)
	{
		return ListCreateEmpty();
	}
	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < v_size; i++) // scorro vettore di liste
	{
		Item* tmp = v[i];
		while (!ListIsEmpty(tmp)) {
			ElemType* e = ListGetHeadValue(tmp);
			res = ListInsertBack(res, e);
			tmp = ListGetTail(tmp);
		}
	}

	return res;
}

//per main 

Item* ListFromArray(const ElemType* arr, size_t size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < size; i++) {
		list = ListInsertBack(list, &arr[i]);
	}
	return list;
}


int main(void) {
	ElemType a[] = { 1, 2 };
	ElemType b[] = { 3, 4, 5 };
	ElemType c[] = { 6 };

	Item* l1 = ListFromArray(a, sizeof(a) / sizeof(ElemType));
	Item* l2 = ListFromArray(b, sizeof(b) / sizeof(ElemType));
	Item* l3 = ListFromArray(c, sizeof(c) / sizeof(ElemType));

	// Array di puntatori a liste
	Item* v[] = { l1, l2, l3 };

	// Concateno tutte le liste
	Item* concatenata = ConcatenaN(v, 3);
	ListWriteStdout(concatenata);
}


