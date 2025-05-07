#include <stdio.h>
#include <stdlib.h>

void BacktrackStrRec(int n,int i ,char *vcurr) {
	if (i==n)
	{
		//stampa soluzione corrente 
		printf("{ ");
		for (int j = 0; j < n; ++j)
		{
			printf("%c",vcurr[j]);
		}
		printf(" },");
		return; // termina ricorsione
	}

	//se valore soluzione non è ancora completo aggiungo un nuovo carattere scelto fra quelli ammissibili(devo provarli tutti )
	for (char c = 'a'; c < 'a' + n; ++c)
	{
		//scelgo carattere i-esimo (da 'a' ad 'a' +n)
		vcurr[i] = c;
		//chiamata ricorsiva 
		BacktrackStrRec(n, i + 1, vcurr);
	}
}

void BackTrackStr(int n) {
	if (n<=0 || n>26)
	{
		return;
	}

	char* vcurr = malloc(n);

	BacktrackStrRec(n, 0, vcurr);

	free(vcurr);
}


int main(void) {

	BackTrackStr(-1);
	puts("");
	BackTrackStr(1);
	puts("");
	BackTrackStr(2);
	puts("");
	BackTrackStr(3);
	return 0;

}