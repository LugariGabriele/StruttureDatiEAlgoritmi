#include "newton.h"
#include <math.h>
/*
* 
Polinomio x^3 -2x avrà size 4 e coeff 0,-2,0,1 


*/

double valutaPolinomio(const Polinomio* p, double x) {
	double res = 0.0;
	for (int i = p->size - 1; i >= 0; i--) {
		res = res * x + p->coeff[i];
	}
	return res;
}

double NewtonRec(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {
	if (max_iter<=0)
	{
		return xn;
	}
	
	double fx = valutaPolinomio(p, xn);
	double dfx = valutaPolinomio(d, xn);

	double x_next = xn - fx / dfx;

	if (fabs(x_next - xn) <= t) {
		return x_next;
	}

	
	return NewtonTailRec(p, d, x_next, t, max_iter - 1);
}



double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {

	return NewtonRec(p, d, xn, t, max_iter);
}