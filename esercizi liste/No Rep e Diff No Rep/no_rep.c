#include "list.h"
#include <stdbool.h>

bool ListContains(const Item* list, const ElemType* value) {
	while (list != NULL) {
		if (ElemCompare(ListGetHeadValue(list), value) == 0) {
			return true;
		}
		list = ListGetTail(list);
	}
	return false;
}



Item* IntersectNoRep(const Item* i1, const Item* i2) {

	Item* noRep_intersect = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {

		ElemType* e1 = ListGetHeadValue(i1);

		Item* i2_tmp = i2;
		
		while (!ListIsEmpty(i2_tmp)) {
			
			ElemType* e2 = ListGetHeadValue(i2_tmp);

			if (ElemCompare(e1,e2)==0)
			{
				if (!ListContains(noRep_intersect, e1)) {// non c'è già valore
				
					noRep_intersect = ListInsertBack(noRep_intersect, e1);
				}
				break; // esco ciclo a avanzo in i1
			}

			i2_tmp = ListGetTail(i2_tmp);
		}

		i1 = ListGetTail(i1);
	}

	return noRep_intersect;
}


Item* DiffNoRep(const Item* i1, const Item* i2) {

	Item* noRep_Diff = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {

		ElemType* e1 = ListGetHeadValue(i1);

		Item* i2_tmp = i2;

		bool presente = false;

		while (!ListIsEmpty(i2_tmp)) {

			ElemType* e2 = ListGetHeadValue(i2_tmp);

			if (ElemCompare(e1, e2) == 0)
			{
				presente = true;
				break; // esco ciclo a avanzo in i1
			}

			i2_tmp = ListGetTail(i2_tmp);
		}

		if (!presente && !ListContains(noRep_Diff,e1))
		{
			noRep_Diff = ListInsertBack(noRep_Diff, e1);
		}

		i1 = ListGetTail(i1);
	}

	return noRep_Diff;
}