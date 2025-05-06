#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc !=3)
	{
		fprintf(stderr,"Il numero dei parametri non è corretto. Sintassi del programma: \"mul <a> <b>\"");
		return 1;
	}

	int valA = atoi(argv[1]);
	int valB = atoi(argv[2]);
	printf("%d", valA * valB);
	return 0;
}