#include <stdlib.h>
#include <string.h>
#include <math.h>
int AtoIRec(const char* str,int i, int j, int res) {
	
	if (str[0] == '-' && j == 0)
	{
		return -res;
	}
	
	if (str[0] == '+' && j == 0)
	{
		return res;
	}
	
	if (str[j]<= '0'||str[j]>='9')
	{
		return 0;
	}
	
	res += ((str[j]-'0') * pow(10, i));

	return AtoIRec(str, ++i, --j, res);

}


int AToI(const char* str) {

	if (str==NULL)
	{
		return 0;
	}
	return AtoIRec(str,0, strlen(str) - 1,0);

}


int main(void) {
	char *str = "4a2";
	AToI(str);
	return 0;
}