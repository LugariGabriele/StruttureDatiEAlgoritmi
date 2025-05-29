#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int IndiceFirstCapitalRec(char* s, int idx) {

	if (isupper(s[idx])!=0) // ritorna 0 se non maiuscolo
	{
		return idx;
	}

	if (s[idx]== '\0') // fine stringa
	{
		return 2;
	}

	IndiceFirstCapitalRec(s, idx + 1);

}

int IndiceFirstCapital(char* s) {

	if (strlen(s)==0)
	{
		return 2;
	}

	return IndiceFirstCapitalRec(s, 0);
}

int main(int argc,char** argv) {

	if (argc!=2)
	{
		return 1;
	}


	char* s = argv[1];
	int len = strlen(s);

	int idx = IndiceFirstCapital(s);
	if (idx == 2) {
		return 2; // nessuna maiuscola o stringa vuota
	}


	printf("%d", idx+1); // più 1 perchè conto elementi della stringa e non parto da 0
	
	return 0;
}