#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"

#include <string.h>
#include <stdlib.h>

#define _unused(x) ((void)(x))

int ElemCompare(const ElemType *e1, const ElemType *e2) {
    return strcmp(e1->name,e2->name);
}

ElemType ElemCopy(const ElemType *e) {
    ElemType copy;
    strcpy(copy.name, e->name);
    strcpy(copy.street, e->street);
    copy.number = e->number;
    strcpy(copy.city, e->city);
    strcpy(copy.province, e->province);
    strcpy(copy.postal_code, e->postal_code);
    return copy;
}

void ElemSwap(ElemType *e1, ElemType *e2) {
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void ElemDelete(ElemType *e) {
    // In questo caso la funzione ElemDelete non deve fare nulla, ma il 
    // compilatore potrebbe segnalare il mancato utilizzo di e, come warning
    // o come errore. Utilizzando la macro _unused sopra definita eliminiamo
    // questo problema.
    _unused(e);
}

int ElemRead(FILE *f, ElemType *e) {

    return fscanf(f, "%d", &e->number);
}

int ElemReadStdin(ElemType *e) {
    return ElemRead(stdin, e);
}

void ElemWrite(const ElemType *e, FILE *f) {
    fprintf(f, "Name: %s, Street: %s %d, City: %s, Province: %s, Postal Code: %s\n",
        e->name, e->street, e->number, e->city, e->province, e->postal_code);
}

void ElemWriteStdout(const ElemType *e) {
    ElemWrite(e, stdout);
}