#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int* nsol) {
	

	if (i == n) //sono in foglia 
	{
		//verifico soluzione 
		int cnt = vcurr[0]; //imposto uguale a primo valore di vcurr (quindi 1 o 0) così dopo posso mettere j-1 in ciclo se errori
		for (int j = 1; j < n; j++)
		{
			if (vcurr[j]) {
				cnt++; //ho un 1 quindi aumento contatore ombrelloni asseganti
			}
			
			if (vcurr[j] == vcurr[j - 1]) { //ho due ombrelloni vicini quindi errore. faccio terminare funzione e torno indietro ricorsione
				return;
			}

		}

		if (cnt==k) //asseganti tutti i ragazzi e bene dato che sono arrivato qui
		{
			(*nsol)++;
			printf("%4d) ", *nsol);
			for (int j = 0; j < n; j++)
			{
				printf("%d ", vcurr[j]);
			}
			printf("\n");
		}

		return; // finita fase controllo sol, torno indietro
	} 

	//i corrisponde al livello dell albero
	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol);


	vcurr[i] = 1;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol);

	
}



int Ombrelloni(int k, int n) {
	
	int nsol = 0;
	bool *vcurr = calloc(n, sizeof(bool)); //inizializza vettore tutti 0
	
	
	OmbrelloniRec(k, n, 0, vcurr, &nsol);

	free(vcurr);
	return nsol;
	
}

int main(void) {
	int nsol;
	Ombrelloni(2, 4);
}