#include <time.h>
#include <stdio.h>

extern int Ombrelloni(int k, int n, int *ncall);
extern int OmbrelloniPruning(int k, int n, int *ncall);

int main(void) {
    int k = 2;
    int n = 4;
    int nsol, tick, tock;
    double elapsed;
    int ncall;

    tick = clock();
    nsol = OmbrelloniPruning(k, n, &ncall);
    tock = clock();
    elapsed = (tock - tick) /(double) CLOCKS_PER_SEC;
    printf("Elapsed Pruning %f\n#chiamate ricorsive: %d\n", elapsed, ncall);


    tick = clock();
    nsol = Ombrelloni(k, n, &ncall);
    tock = clock();
    elapsed = (tock - tick) /(double) CLOCKS_PER_SEC;
    printf("Elapsed NO Pruning %f\n#chiamate ricorsive: %d\n", elapsed, ncall);


    
    return 0;
}