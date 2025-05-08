#ifndef NEWTON_H
#define NEWTON_H

#include<stdlib.h>

typedef struct {
	int* coeff;
	size_t size;
}Polinomio;

extern double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter);

#endif // !NEWTON_H
