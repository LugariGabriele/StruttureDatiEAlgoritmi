#define  _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>

Node* TreeReadRec(FILE* f) {

	char ch; // buffer per caratteri letti

	if (fscanf(f, " %c", &ch) != 1) // riesce a leggere ( metto spazio prima di %c così non legge whitespace)
	{
		return NULL; // fine file o errore
	}

	//se foglia
	if (ch == '.')
	{
		if (fscanf(f, " %c", &ch) != 1) { // provo a leggere valore della foglia
			return NULL;
		}

		ElemType e = ch;
		return TreeCreateRoot(&e, NULL, NULL);
	}


	//se arrivato qui è nodo normale
	ElemType e = ch;
	Node* left = TreeReadRec(f); // prima sinistra perchè nodi normali seguiti sempre da carattere del figlio sx
	Node* right = TreeReadRec(f);

	return TreeCreateRoot(&e, left, right); // creo nodo con i figli
}


Node* TreeRead(const char* filename) {

	// si deve leggere da un file che contiene un insieme di caratteri e costruire albero corrispondente,
	// le foglie nel file sono precedute da . (es .x), ogni carattere alfanumerico corrisponde ad un nodo
	// ogni nodo è seguito dal dal figlio sinistro(che a sua volta può avere figli) e poi da quello dx(anche lui può avere figli)
	//ogni nodo apparte le foglia ha sempre entrambi i figli
	// i white space nel file non hanno effetto
	// (a .x b d .s .u .c)



	//ho modificato elemtype in typedef char e anche writeStdout %c senno stampaza numeri ascii al posto del carattere

	FILE* f = fopen(filename, "r");

	Node* tree = TreeReadRec(f);
	fclose(f);

	return tree;
}

int main(void) {
	
	Node* t = TreeRead("albero_01.txt");

	if (t) {
		TreeWriteStdoutPreOrder(t);  // Output atteso: a x b d s u c
		printf("\n");

	}
	else {
		printf("Errore nella lettura dell'albero.\n");
	}

	return 0;
}