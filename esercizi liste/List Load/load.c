#include "list.h"
#include "elemtype.h"



Item* ListLoad(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return ListCreateEmpty();

	}


	ElemType e; // var per salvare elem letto
	Item* List = ListCreateEmpty();



	while (ElemRead(f, &e) == 1) {

		List = ListInsertHead(&e, List);
	}

	fclose(f);
	return List;
}
//
//int main(void) {
//
//	Item* l = ListLoad("data_01.txt");
//	ListWriteStdout(l);
//
//}
