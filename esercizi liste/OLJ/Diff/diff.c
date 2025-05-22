#include "list.h"
#include <stdbool.h>

Item* Diff(const Item* i1, const Item* i2) {

	Item* list_differenza = ListCreateEmpty();


	while (i1 != NULL) {

		ElemType* e1 = ListGetHeadValue(i1);

		Item* i2_tmp = i2;

		bool presente = false;


		while (i2_tmp != NULL) {

			ElemType* e2 = ListGetHeadValue(i2_tmp);

			if (ElemCompare(e1, e2) == 0)
			{
				presente = true;
				break;
			}

			i2_tmp = ListGetTail(i2_tmp);

		}
		if (!presente) // aggiungo elem
		{
			list_differenza = ListInsertBack(list_differenza,e1);
		}

		//scorro i1
		i1 = ListGetTail(i1);
	}


	return list_differenza;
}
//
////	// usata per creare lista da file
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
//	Item *res = Diff(i1, i2);
//	ListWriteStdout(res);
//}
//
