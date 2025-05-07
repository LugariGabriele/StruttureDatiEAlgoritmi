#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void RegoleRec(const char* r, int n, int i, int* vcurr, bool* usati) {

	//caso base ho una sequenza di n+1 elementi quindi sono allivello n+1 dell albero
	if (i == n + 1)
	{
		//stampo soluzione
		for (int j = 0; j < n + 1; j++)
		{
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}

	//scelgo uno dei valori in [1,n+1]
	for (int j = 1; j <= n + 1; j++)
	{
		bool I = !usati[j - 1]; //numero non ancora stato usato
		bool a = i == 0; //primo elemento di vcurr quindi senza vincoli

		bool b = (r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[i - 1] < j; //rispetato incremento num precendente è < j
		bool c = (r[i - 1] == 'd' || r[i - 1] == 'D') && vcurr[i - 1] > j;
		bool II = a || b || c;

		if (I && II)
		{
			//se sono qui posso segliere j
			usati[j - 1] = 1; //segno che l'ho usato 
			vcurr[i] = j;
			RegoleRec(r, n, i + 1, vcurr, usati);
			usati[j - 1] = 0;
		}
	}
}



void Regole(const char* r) {
	int n = strlen(r);
	int* vcurr = malloc((n + 1) * sizeof(int));
	bool* usati = calloc(n + 1, sizeof(bool));

	RegoleRec(r, n, 0, vcurr, usati);

	free(vcurr);
	free(usati);
}

int main(void) {
	Regole("ii");
	puts("");
	Regole("d");
}