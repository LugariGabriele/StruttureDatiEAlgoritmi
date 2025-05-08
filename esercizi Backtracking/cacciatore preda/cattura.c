#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void CacciatorePredaRec(const char* v, size_t v_size, int u, int* vcurr, int* vbest, int* nsol, int* presi_best, int i, int presi) {

    if (i == v_size) {
        for (int j = 0; j < v_size; j++) {

            if (v[j] == 'C' && vcurr[j] != -1) {
                int num = j - u;

                if (v[vcurr[j]] == 'P' && ((vcurr[j] >= num) && (vcurr[j] <= j + u))) {
                    vcurr[vcurr[j]] = -2; // metto preda come presa
                    presi++;
                }
                else {
                    return;
                }
            }
        }

        for (int k = 0; k < v_size; k++) {
            printf("| %4d ", vcurr[k]); // stampa compatta
        }
        printf("|\n");
        (*nsol)++;

        if (presi > *presi_best) {
            memcpy(vbest, vcurr, v_size * sizeof(int));
        }

        for (int g = 0; g < v_size; g++) {  // reimposto tutto vcurr a non preso
            if (v[g] == 'P') {
                vcurr[g] = -1;
            }
        }
        return;
    }

    if (v[i] == 'P') {
        CacciatorePredaRec(v, v_size, u, vcurr, vbest, nsol, presi_best, i + 1, presi);
    }
    if (v[i] == 'C') {
        int j = -1;
        int s = v_size;
        for (; j < s; j++) {
            vcurr[i] = j; // provo a prendere elemento a indice j 
            CacciatorePredaRec(v, v_size, u, vcurr, vbest, nsol, presi_best, i + 1, presi);
        }
    }
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
    int* vcurr = calloc(v_size, sizeof(int));
    int* vbest = calloc(v_size, sizeof(int));
    int nsol = 0;
    int presi_best = 0;

    for (int i = 0; i < v_size; i++) {
        vcurr[i] = -1;
    }

    for (int c = 0; c < v_size; c++)
    {
        printf("| %2d-%c ", c, v[c]);
    }
    printf("|\n");
    CacciatorePredaRec(v, v_size, u, vcurr, vbest, &nsol, &presi_best, 0, 0);

    free(vcurr);

    return vbest;
}

int main(void) {
    char s[] = { 'C','P','P','C','P' };
    size_t size = 5;
    int u = 1;
    CacciatorePreda(s, size, u);
}
