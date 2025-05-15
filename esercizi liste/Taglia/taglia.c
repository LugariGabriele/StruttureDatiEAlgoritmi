#include "list.h"


Item* Taglia(const Item* i, int n) {

	if (n<0)
	{
		return i;
	}

	int size = 0;
	Item* tmp = i;

	while (tmp != NULL) {
		size++;
		tmp = tmp->next;
	}

	if (n >= size || n==0) {
		ListDelete(i);
		return ListCreateEmpty();
	}

	Item* curr = i;
	int idx = 1;

	//vado fino a nodo n-esimo
	while (curr != NULL && idx < n) {
		curr = curr->next;
		idx++;
	}

	if (curr != NULL && curr->next != NULL) {
		ListDelete(curr->next);  // libera la coda rimanente
		curr->next = NULL;       // taglia la lista qui
	}

	return i;
}

int main(void) {

	ElemType* a = 1;
	ElemType* b = 2;
	ElemType* c = 1;
	ElemType* d = 1;

	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	ListWriteStdout(list);

	list = Taglia(list, 2);
	ListWriteStdout(list);

}
