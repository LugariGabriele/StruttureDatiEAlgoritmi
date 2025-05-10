#include "vettore.h"
#include "elemtype.h"
#include <stdlib.h>

int ElemCompare(const ElemType* a, const ElemType* b) {
	return (*a) - (*b);
}

int VectorFind(const Vector* v, const ElemType* e) {



	//for (size_t i = 0; i < v->size ; i++)
	//{
	//	if (ElemCompare(&v->data[i],&e)==0) // sono stesso elem
	//	{
	//		return i;
	//	}
	//}

	//return -1;    METODO VA BENE MA è O(n)


	//dobbiamo trovare prima posizione dell elemento e in v 
	//quindi BINARY SEARCH LOWER BOUND O(n log(n))


	if (v == NULL || v->size == 0) {
		return -1;
	}


	int first = 0;
	int last = v->size - 1;
	int middle, mid;

	while (first < last) {
		mid = (first + last) / 2;
		middle = v->data[mid];
		if (ElemCompare(&middle, e) < 0) // elemento mediana è < di quello cercato
		{
			//cerco a dx di mediana
			first = mid + 1;
		}
		else
		{
			last = mid; // cerco sx di mediana
		}

		if (first == last && &v->data[first] < e)
		{
			first++;
		}
	}

	//ritorno indice lower bound
	if (first == last)
	{
		return first;
	}
	else
	{
		return -1;
	}

}
int main(void) {

	Vector* v = malloc(sizeof(Vector));

	v->size = 5;
	v->capacity = 5;
	v->data = malloc(10 * sizeof(ElemType));

	ElemType data[] = { -2, 1, 3, 3, 4, 4, 4, 5, 12, 34 };
	for (size_t i = 0; i < 10; ++i) {
		v->data[i] = data[i];
	}

	ElemType target = 4;

	int i = VectorFind(v, &target);
}