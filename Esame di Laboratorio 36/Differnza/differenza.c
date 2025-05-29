#include <string.h>
#include <stdlib.h>


char Differenza(const char* s, const char* p) {
	int freq_s[256] = { 0 }; // creo array con ogni possibile valore ASCII 256 
	int freq_p[256] = { 0 };

	// conta frequenze in s
	for (int i = 0; s[i] != '\0'; i++) {
		freq_s[s[i]]++; //viene numero per ogni carattere di s freq['a']=1, freq['b'] = 1 ...
	}

	for (int i = 0; p[i] != '\0'; i++) {
		freq_p[p[i]]++;
	}

	// trova il carattere con freq_p > freq_s
	for (int i = 0; i < 256; i++) {
		if (freq_p[i] > freq_s[i]) {
			return (char)i;
		}
	}

	return '\0';
}