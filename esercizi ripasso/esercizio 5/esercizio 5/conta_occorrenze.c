#include <string.h>
#include <stdio.h>

int ContaOccorrenze(const char* filename, const char* str) {
	if (str== NULL)
	{
		return 0;
	}
	FILE* file = fopen(filename, "r");
	if (file== NULL)
	{
		return 0;
	}
	char parola[100];
	int contatore = 0;
	while (fscanf(file, "%99s", parola) == 1) { // ritorna che almeno un valore è letto correttamente e lo mette in parola 
		if (strcmp(parola,str)==0)
		{
			contatore++;
		}
	}
	fclose(file);
	return contatore;
}