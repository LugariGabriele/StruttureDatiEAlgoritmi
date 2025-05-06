#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool IsPalindromoRec(const char* str,int i,int j,bool res){
	if (i==(strlen(str)/2))
	{
		return res;
	}

	if (str[i]==str[j])
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return IsPalindromoRec(str, ++i, --j, res);
}


bool IsPalindromo(const char* str) {
	if (str==NULL)
	{
		return false;
	}
	if (strlen(str)==0)
	{
		return true;
	}
	return IsPalindromoRec(str, 0, strlen(str)-1,false);
}

int main(void) {
	char* str = "ossesso";
	IsPalindromo(str);
	return 0;
}