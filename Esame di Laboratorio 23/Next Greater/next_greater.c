#include "next_greater.h"
#include <limits.h>
#include <stdlib.h>

int ContaElemList(const Item* i) {

	int count = 0;
	const Item* curr = i;
	while (curr != NULL) {

		curr = curr->next;
		count++;
	}

	return count;
}


ElemType* NextGreater(const Item* list, size_t* answer_size) {

	if (ListIsEmpty(list))
	{
		*answer_size = 0;
		return NULL;
	}

	int len = ContaElemList(list);
	ElemType* answer = malloc(len * sizeof(ElemType));


	int count = 0;


	const Item* curr = list;

	while (curr != NULL) {
		bool trovato = false;
		ElemType vcurr = *ListGetHeadValue(curr);
		const Item* cercaNum = curr->next;

		while (cercaNum != NULL) {

			ElemType VcercaNum = *ListGetHeadValue(cercaNum);

			if (VcercaNum > vcurr) //ho trovato maggiore
			{
				answer[count] = VcercaNum;
				trovato = true;
				break;
			}
			cercaNum = cercaNum->next;
		}


		if (!trovato)
		{
			answer[count] = INT_MIN;

		}


		count++;
		curr = curr->next;
	}

	*answer_size = count;
	return answer;
}


//
//int main(void) {
//
//	int v[] = { 2,3,1,4,7,2 };
//	int size = sizeof(v) / sizeof(v[0]);
//
//	Item* i = ListCreateEmpty();
//
//	for (int j = 0; j < size; j++)
//	{
//		i = ListInsertBack(i, &v[j]);
//	}
//
//	size_t answer_size;
//	ElemType* asnwer = NextGreater(i, &answer_size);
//}