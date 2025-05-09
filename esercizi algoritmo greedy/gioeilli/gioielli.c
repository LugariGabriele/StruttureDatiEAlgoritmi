#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"



Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	FILE* f = fopen(filename, "r");
	if (!f)
	{
		return NULL;
	}

	Gioiello* gioielli = NULL;
	int i = 0;

	Gioiello tmp;
	while (fscanf(f, "%d %f %f", &tmp.codice, &tmp.peso, &tmp.prezzo) == 3) { //va fino a che riesce a leggere tutti e 3 valori
		gioielli = realloc(gioielli, (i + 1) * sizeof(Gioiello)); // rialloco vettore gioielli
		gioielli[i].codice = tmp.codice;
		gioielli[i].peso = tmp.peso;
		gioielli[i].prezzo = tmp.prezzo;
		i++;
	}

	float* rapporto = calloc(i, sizeof(float));
	for (int j = 0; j < i; j++) // creo rapporto per ogni gioiello
	{
		rapporto[j] = gioielli[j].peso / gioielli[j].prezzo;
	}

	//ordino i gioielli in base al rapporto decrescentemente
	for (int k = 0; k < i - 1; k++)
	{
		for (int j = 0; j < i - 1 - k; j++)
		{
			if (rapporto[j] < rapporto[j + 1]) {
				float tmp_rapp = rapporto[j];
				rapporto[j] = rapporto[j + 1];
				rapporto[j + 1] = tmp_rapp;

				Gioiello gioiello_tmp = gioielli[j];
				gioielli[j] = gioielli[j + 1];
				gioielli[j + 1] = gioiello_tmp;
			}
		}
	}

	Gioiello* gioielli_scelti = NULL;
	int comprati = 0;
	float spesa = 0.0;
	for (int j = 0; j < i; j++)
	{
		if (spesa + gioielli[j].prezzo <= budget) {
			gioielli_scelti = realloc(gioielli_scelti, (comprati + 1) * sizeof(Gioiello));
			gioielli_scelti[comprati] = gioielli[j];
			comprati++;
			spesa += gioielli[j].prezzo;
		}
	}

	//salvo dimensione di gioielli scelti in ret_size
	*ret_size = comprati;

	fclose(f);
	free(gioielli);
	free(rapporto);

	return gioielli_scelti;
}

//
//int main(void) {
//	size_t ret=0;
//	CompraGioielli("gioielli_2.txt", 200, &ret);
//}