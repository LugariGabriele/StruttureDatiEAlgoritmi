#include <limits.h>
#include <stdbool.h>

int DivisioneNegativiRec(int a, int b,int res) {
	if (a-b<0)
	{
		return res;
	}

	return DivisioneNegativiRec(a - b, b, ++res);
}



int DivisioneNegativi(int a, int b) {
	if (b==0)
	{
		return INT_MAX;
	}

	bool segno = false;
	if (a<0)
	{
		segno = !segno;
		a = -a;
	}

	if (b < 0)
	{
		segno = !segno;
		b = -b;
	}
	
	int res = DivisioneNegativiRec(a, b, 0);
	return segno ? -res : res;

}

//int main(void) {
//	DivisioneNegativi(-4, -2);
//	return 0;
//}