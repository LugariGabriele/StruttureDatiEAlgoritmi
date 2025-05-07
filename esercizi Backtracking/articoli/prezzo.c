#include "prezzo.h"
#include <stdio.h>
#include <stdbool.h>



void TrovaArticolirec(const struct Articolo* a, size_t size_a, int sum, int* vcurr, int sumcor, int i)
{
	if (i == size_a) //non ci sono più articoli da leggere
	{
		if (sumcor == sum)
		{
			for (size_t j = 0; j < size_a; j++)
			{
				if (vcurr[j] == 1)
				{
					printf("%s, ", a[j].nome);
				}
			}
			printf("\n");
		}
		return;
	}



	vcurr[i] = true;
	TrovaArticolirec(a, size_a, sum, vcurr, sumcor + a[i].prezzo, i + 1);
	vcurr[i] = false;
	TrovaArticolirec(a, size_a, sum, vcurr, sumcor, i + 1);
}

void TrovaArticoli(const struct Articolo* a, size_t size_a, int sum)
{
	int* vcurr = calloc(size_a, sizeof(int));

	TrovaArticolirec(a, size_a, sum, vcurr, 0, 0);
}

int main(void) {
	struct Articolo a[] = {
	{.nome = "Monopoli", .prezzo = 20},
	{.nome = "Carcassone", .prezzo = 30},
	{.nome = "Perudo" , .prezzo = 20},
	{.nome="Risiko", .prezzo =30},
	};

	size_t size = sizeof(a) / sizeof(struct Articolo);
	TrovaArticoli(a, size,50);
}