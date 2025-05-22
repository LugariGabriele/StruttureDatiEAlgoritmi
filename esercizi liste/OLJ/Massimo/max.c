#include "list.h"

const ElemType* MaxElement(const Item* i) {
	// complessità O(n) devo per froza scorrere tuttii nodi 
	// se ordinata decrescente O(1) prendo primo nodo


	if (ListIsEmpty(i)) {
		return NULL;
	}

	const ElemType* max = ListGetHeadValue(i); // inizializzo come il primo

	while (!ListIsEmpty(i)) {

		const ElemType* e_curr = ListGetHeadValue(i);

		if (ElemCompare(max, e_curr) < 0) // max - curr <0 --> curr è più grande
		{
			max = e_curr;
		}

		i = ListGetTail(i);
	}

	return max;
}
