#define _CRT_SECURE_NO_WARNINGS
#include "list.h"


Item* ListLoad(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return ListCreateEmpty();
	}

	Item* list = ListCreateEmpty();
	int x, y;

	while (fscanf(f, "%d %d", &x, &y) == 2) {
		ElemType e = { .x = x,.y = y };
		list = ListInsertHead(&e, list);
	}

	fclose(f);
	return list;
}


int main(void) {

	Item *list = ListLoad("coords_02.txt");
	ElemWriteStdout(list);
}