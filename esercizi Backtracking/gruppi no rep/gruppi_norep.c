#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[21];
}Studente;


bool verifica(Studente* vcurr, int vcurr_size, Studente* tocheck) {
	//primo che controlla per forza true 0<0
	for (int i = 0; i < vcurr_size; i++)
	{
		bool uguale_iniziale = vcurr[i].nome[0] == tocheck->nome[0];
		bool iniziale_cons = (vcurr[i].nome[0] == tocheck->nome[0] + 1) || (vcurr[i].nome[0] == tocheck->nome[0] - 1);

		if (uguale_iniziale || iniziale_cons)
		{
			return false;
		}
	}
	return true;
}

void GruppiNoRepRec(Studente* stud, int k, Studente* vcurr, int vcurr_size, int i, int n, int* nsol) {

	if (vcurr_size == n) //gruppo comleto quindi stampo sol
	{

		printf("{ %s", vcurr[0].nome);
		for (int j = 1; j < n; j++)
		{
			printf(", %s", vcurr[j].nome);
		}
		printf(" }\n");
		(*nsol)++;
		return;
	}

	if (i >= k)
	{
		return;
	}

	if (verifica(vcurr, vcurr_size, stud + i))
	{
		strcpy(vcurr[vcurr_size].nome, stud[i].nome);
		GruppiNoRepRec(stud, k, vcurr, vcurr_size + 1, i + 1, n, nsol);//passo a nome dopo
	}

	//in ogni caso provo a costruire la sol che non usa nome i-esimo incrementando i+1 ma non vcurrsize 
	GruppiNoRepRec(stud, k, vcurr, vcurr_size, i + 1, n, nsol);
}



int GruppiNoRep(const char* filename, int n) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return 0;
	}

	int k = 0; // grandezza array studenti
	Studente* stud = NULL; //array sudenti

	while (1) {
		stud = realloc(stud, (k + 1) * sizeof(Studente));
		if (fscanf(f, "%20s", stud[k].nome) != 1) //non trovo più da leggere nomi
		{
			stud = realloc(stud, k * sizeof(Studente));
			break;
		}
		k++;
	}

	fclose(f);

	if (n<1 || n>k)
	{
		return 0;
	}

	Studente* vcurr = malloc(n * sizeof(Studente));
	int nsol = 0;

	GruppiNoRepRec(stud, k, vcurr, 0, 0, n, &nsol);

	free(stud);
	free(vcurr);

	return nsol;
}

int main(void) {
	int s;

	s = GruppiNoRep("nomi_01.txt", 2);
}