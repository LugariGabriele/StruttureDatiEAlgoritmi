#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


void SpringArrangementsRec(const char* record, int idx, char* vcurr, int* nsol, int len) {

	if (idx == len) {
		vcurr[len] = '\0'; // aggiungo terminatore così diventa stringa
		printf("%s\n", vcurr);
		(*nsol)++;
		return;
	}

	if (idx>= len) // controllo per eventuali cicli infiniti
	{
		return;
	}

	if (record[idx] == '?') {
		vcurr[idx] = '#';
		SpringArrangementsRec(record, idx + 1, vcurr, nsol, len);
		vcurr[idx] = '.';
		SpringArrangementsRec(record, idx + 1, vcurr, nsol, len);
	}
	else {
		vcurr[idx] = record[idx];
		SpringArrangementsRec(record, idx + 1, vcurr, nsol, len);
	}


}

int SpringArrangements(const char* record) {
	
	int len = strlen(record);
	char* vcurr = malloc(len + 1); // +1 per il terminatore
	int nsol = 0;

	SpringArrangementsRec(record, 0, vcurr, &nsol, len);
	
	free(vcurr);
	return nsol;
}


//
//int main(void) {
//
//
//	char* s = ".??..??...?##.";
//	SpringArrangements(s);
//
//}