#include "tree.h"
#include <stdbool.h>
#include <stdio.h>

void TreeWriteRec(const Node* t, FILE* f, int depth) {

	if (t == NULL)
	{
		return;
	}

	//stampa 4*d spazi
	for (int i = 0; i < 4 * depth; i++)
	{
		fputc(' ', f);
	}

	if (TreeIsLeaf(t))
	{
		fprintf(f, ".%c\n", t->value);
	}
	else
	{
		fprintf(f, "%c\n", t->value);
	}

	// faccio ricorsione su figli e aumento profonità prima sx dato che dopo radice c'è nodo a sx
	TreeWriteRec(t->left, f, depth + 1);
	TreeWriteRec(t->right, f, depth + 1);


}

bool TreeWrite(const Node* t, const char* filename) {

	//stesso formato di read, ogni valore deve essere scritto su una linea differente, preceduto dal carattere spazio ripetuto 4*d volte 
	// d è la profondità del nodo

	FILE* f = fopen(filename, "w");

	if (!f)
	{
		return false;
	}

	TreeWriteRec(t, f, 0);
	fclose(f);

	return true;
}

int main(void) {


	//	 a
	//	/ \
	//	b   c
	//		/
	//	   d
	Node* t = TreeCreateRoot(&(ElemType) { 'a' },
		TreeCreateRoot(&(ElemType) { 'b' }, NULL, NULL),
		TreeCreateRoot(&(ElemType) { 'c' },
			TreeCreateRoot(&(ElemType) { 'd' }, NULL, NULL),
			NULL)
	);

	if (TreeWrite(t, "output.txt")) {
		printf("Albero scritto con successo in output.txt\n");
	}
	else {
		printf("Errore durante la scrittura del file.\n");
	}

	TreeDelete(t);
	return 0;
}