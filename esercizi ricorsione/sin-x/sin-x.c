#include <stddef.h>
#include <cfloat>
#include <math.h>

double fattoriale(double n) {
	double fact = 1;
	if (n>1)
	{
		for (size_t i = 2; i <=n; i++)
			{
				fact = fact * i;
			}
	}
	return fact;
	
}

double SenRec(double x, int i,double n, double res,double fact) {
	if (n==i)
	{
		return res;
	}
	
	fact = fattoriale(2 * n + 1);
	res += (pow(-1, n) / fact) * pow(x, (2 * n + 1));
	return SenRec(x,i, n+1, res, fact);
}



double Sen(double x, int i) {
	if (i < 0) {
		return DBL_MIN;
	}
	return SenRec(x, i, 0,0,1);
}

int main(void) {
	double val = Sen(1.57, 5);
	return 0;
}