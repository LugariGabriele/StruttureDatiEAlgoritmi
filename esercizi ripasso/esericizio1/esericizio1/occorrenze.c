#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	//controllo se sono numero giusto
	if (argc!=3||strlen(argv[2])!=1)
	{
		printf("Il numero di parametri non è corretto. Sintassi del programma: 'occcorrenze <s> <c>'");
		return 1;
	}
	int occorrenze=0;
	int i = 0;
	char carattere = argv[2][0];
	while (argv[1][i] != '\0') {
		if (argv[1][i]== carattere)
		{
			occorrenze++;
		}
		i++;
	}
	printf("%d", occorrenze);
	return 0;
}