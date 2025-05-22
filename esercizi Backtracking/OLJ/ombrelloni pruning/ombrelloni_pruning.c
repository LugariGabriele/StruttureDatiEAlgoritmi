#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void OmbrelloniPruningRec(int k, int n, int i, bool *vcurr, int cnt, int *nsol, int *ncall) {
    
    (*ncall)++;
    if (cnt == k) { //primo caso base in questo caso posso metterlo fuori dato che ho count com parametro
        (*nsol)++;
        printf("%4d) ", *nsol);
        for (int j = 0; j < n; ++j) {
            printf("%d ", vcurr[j]);
        }
        /*for (int j = i; j < n; ++j){
            printf("0 ");
        }*/
        puts("");
        return;
    }

    if (i == n) { // sono arrivato ad una foglia e questa soluzione non è valida dato che non sono entrato nell if di prima
        return;
    }


    // Versione con ciclo for
    /*for (int j = 0; j < 2; ++j) {
        vcurr[i] = j;
        if (j == 0 || (i == 0 || !vcurr[i - 1])){
            OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt + j, nsol, ncall);
        }
        vcurr[i] = 0;
    }*/

    // Versione chiamate ricorsive "srotolate"
    vcurr[i] = 0;
    OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt, nsol, ncall);

    //ramo 1 può essere preso solo se sono nella radice dell albero oppure se nella scelta prima non è stato preso un ragazzo
    if (i == 0 || !vcurr[i - 1]) { 
        vcurr[i] = 1;
        OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt + 1, nsol, ncall); //incrememtno cnt
        vcurr[i] = 0; // devo metterlo perchè senno quando interromo 1001 , il backtrack torna indietro con l'esecuzione e va a 101 e anche qua si
                        // reinterrompe dato che ho trovato sol(ho k=2=count e vanno bene 101..) ma dato che ho bloccato prematuramente senza neanche entrare
                        // nella foglia rimane il vcur[4] della prima che era a 1 quindi 1011 così quando all inizio sono a 1001 e torno indietro
                        // diventa 1000 prima di fare 101...
    }
}


int OmbrelloniPruning(int k, int n, int *ncall) {
    int nsol = 0;
    bool *vcurr = calloc(n, sizeof(bool));

    (*ncall) = 0;
    OmbrelloniPruningRec(k, n, 0, vcurr, 0, &nsol, ncall);

    free(vcurr);
    return nsol;
}
