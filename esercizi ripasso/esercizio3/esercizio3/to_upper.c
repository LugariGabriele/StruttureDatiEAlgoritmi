#include <stdint.h>


void ToUpper(char* str) {

	if (str== NULL)
	{
		return;
	}

	char* p = str;
	while (*p != '\0') {
		if (*p >= 'a' && *p <= 'z') {
			*p = *p - 32;
		}
		p++;
	}
}
//
//int main(void) {
//	char str[] = "cIAo";
//	ToUpper(str);
//	
//}