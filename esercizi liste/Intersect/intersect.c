#include "list.h"

Item* Intersect(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2))
	{
		return ListCreateEmpty();
	}

	Item* list_intersect = ListCreateEmpty();

	while (1) {

		ElemType* e1 = ListGetHeadValue(i1);

		Item* i2_tmp = i2;
		while (1) {
			ElemType* e2 = ListGetHeadValue(i2_tmp);

			if (ElemCompare(e1, e2) == 0) // se stesso numero
			{
				list_intersect = ListInsertBack(list_intersect, e1);
				break; // esco appena trovo numero(evito di riscriverlo in caso ci sia un doppione)
			}

			// scorro lista 2
			i2_tmp = ListGetTail(i2_tmp);
			if (i2_tmp == NULL)
			{
				break;
			}
		}

		// scorro lista 1
		i1 = ListGetTail(i1);
		if (i1 == NULL)
		{
			break;
		}
	}


	return list_intersect;
}

//
//	// usata per creare lista da file
//Item* ListLoad(const char* filename) {
//
//	FILE* f = fopen(filename, "r");
//	if (!f)
//	{
//		return ListCreateEmpty();
//
//	}
//
//
//	ElemType e; // var per salvare elem letto
//	Item* List = ListCreateEmpty();
//
//
//
//	while (ElemRead(f, &e) == 1) {
//
//		List = ListInsertBack(List, &e);
//	}
//
//	fclose(f);
//	return List;
//}
//
//int main(void) {
//
//	Item* i1 = ListLoad("data_00.txt");
//	Item* i2 = ListLoad("data_01.txt");
//
//	Item *res = Intersect(i1, i2);
//	ListWriteStdout(res);
//}