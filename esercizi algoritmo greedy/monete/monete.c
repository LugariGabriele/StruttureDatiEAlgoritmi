#include <stdio.h>
#include <stdlib.h>


int* Monete(int* tagli, size_t tagli_size, int budget) {

	if (budget <= 0)
	{
		return NULL;
	}
	int* soluzione = calloc(tagli_size, sizeof(int));
	if (soluzione == NULL)
	{
		return NULL;
	}



	for (int i = 0; i < tagli_size; i++)
	{
		soluzione[i] = budget / tagli[i]; // quante monete[i] ci stanno nel budget
		budget -= soluzione[i] * tagli[i];
	}

	return soluzione;
}

//int main(void) {
//	int tagli[] = { 50,20,10,5,2,1 };
//	Monete(tagli, 6, 126);
//	return 0;
//}