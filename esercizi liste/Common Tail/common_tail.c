#include "list.h"

int Size(const Item* l) {
    int len = 0;
    while (l != NULL) {
        len++;
        l = l->next;
    }
    return len;
}

Item* CommonTail(const Item* i1, const Item* i2) {

	//per coda comune si intende che da un certo  punto hanno gli stessi nodi(stessa memoria)
    //scorro parallelo le due liste con puntatori e controlle se puntano a stesso indirizzo di mem

    int len1 = Size(i1);
    int len2 = Size(i2);

    //allineo le distanze  così partono pari
    while (len1 > len2) {
        i1 = i1->next;
        len1--;
    }
    while (len2 > len1) {
        i2 = i2->next;
        len2--;
    }


    while (i1 != NULL && i2 != NULL) { // scorro parallelamente
        
        if (i1 == i2) {
            return i1; //indirizzo Inizio della coda comune
        }
        i1 = i1->next;
        i2 = i2->next;
    }

    return NULL;
}