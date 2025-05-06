#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct 
{
	char nome[20];

}Studenti;


int GruppiRec(int n, Studenti studenti, int i,int *nsol,Studenti da_controllare, bool *vcur ) {
	if (i==n)
	{
		
	}

}


int Gruppi(const char* filename, int n) {
	if (n<1)
	{
		return 0;
	}
	int nsol = 0;

	FILE* file = fopen(filename, "r");
	if (file==NULL)
	{
		return 0;
	}
	bool* vcur = malloc(n * sizeof(bool));
	Studenti *studenti = malloc(n * sizeof(Studenti));
	
	int num = 0;
	while (fscanf(file, "%20s", studenti[num]) == 1 && n > 0) {
		if (!isupper(studenti[num].nome[0]))
		{
			printf("Errore iniziale del nome: %s non maisucolo \n",studenti[num]);
			continue;
		}
		
		int valido = 1;
		for ( int j = 1; studenti[num].nome[j]!='0'; j++)
		{
			if (!islower(studenti[num].nome[j])) {
				printf("Errore carattere  minuscolo atteso %s \n", studenti[num]);
				valido = 0;
				break;
			}
		}

		if (valido)
		{
			n--;
			num++;
		}

	}
	
	fclose(file);
}