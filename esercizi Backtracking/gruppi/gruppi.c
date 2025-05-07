#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

int GruppiRec(Studente* stud, int k, Studente* vcurr, int i, int n, int* nsol) {

	if (i == n) //caso gruppo completo
	{
		//stampo soluzione
		printf("{ %s", vcurr[0].nome);
		for (int j = 1; j < n; j++)
		{
			printf(", %s", vcurr[j].nome);
		}
		printf(" }\n");
		(*nsol)++;
		return;
	}

	for (int j = 0; j < k; j++)
	{
		if (verifica(vcurr, i, stud + j)) { //gli passo i come grandezza del for perchè deve controllare tutti i nomi che ci sono dentro con la possibile aggiunta
			strcpy(vcurr[i].nome, stud[j].nome);
			GruppiRec(stud, k, vcurr, i + 1, n, nsol);
		}
	}
}

int Gruppi(const char* filename, int n) {

	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		return 0;
	}

	Studente* stud = NULL; //vettore di studenti

	int k = 0; // dimensione vettore stud quindi quanti nomi ho(num massimo di figli che ha un nodo)

	while (1) {
		stud = realloc(stud, sizeof(Studente) * (k + 1));
		if (fscanf(f, "%20s", stud[k].nome) != 1)
		{
			//se non ci sono più nomi la realloc a messo spazio per uno studente di troppo 
			stud = realloc(stud, sizeof(Studente) * k);
			break;
		}
		k++;
	}

	fclose(f);
	if (n<1 || n>k)
	{
		free(stud);
		return 0;
	}

	//preparo vettore soluzione
	Studente* vcurr = malloc(n * sizeof(Studente));
	int nsol = 0;

	GruppiRec(stud, k, vcurr, 0, n, &nsol);

	free(stud);
	free(vcurr);

	return nsol;
}

int main(void) {
	Gruppi("nomi_01.txt", 2);
	return 0;
}