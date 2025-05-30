#include "merge.h"
#include <stdlib.h>

#include "merge.h"
#include "elemtype.h"
#include <stdlib.h>

void MergeInBetweenZeros(Item* i) {
    if (i == NULL) return;

    Item* current = i;

    while (current != NULL) {
        if (*(ListGetHeadValue(current)) == 0) { // trovato il primo zero
            Item* first_zero = current;
            Item* runner = ListGetTail(current);
            int sum = 0;
            int count = 0;
            int found_second_zero = 0; // bool per controllo

            // Conta e somma i nodi tra i due zeri
            while (runner != NULL) {
                if (*(ListGetHeadValue(runner)) == 0) {
                    found_second_zero = 1;
                    break;
                }
                sum += *(ListGetHeadValue(runner));
                ++count;
                runner = ListGetTail(runner);
            }

            // Se meno di 1 elemento tra gli zeri, NON fare nulla
            if (found_second_zero && count > 0) {
                // Elimina i nodi intermedi
                Item* to_delete = ListGetTail(first_zero);
                Item* next;

                while (to_delete != runner) {
                    next = ListGetTail(to_delete);
                    ElemDelete((ElemType*)&to_delete->value);
                    free(to_delete);
                    to_delete = next;
                }

                // Crea il nodo somma
                Item* sum_node = malloc(sizeof(Item));
                sum_node->value = ElemCopy(&sum);
                sum_node->next = runner;

                first_zero->next = sum_node;
                current = runner;
            }
            else {
                // Nessun secondo zero o zeri consecutivi
                current = ListGetTail(current);
            }
        }
        else {
            current = ListGetTail(current);
        }
    }
}



//int main(void) {
//
//	ElemType a = 1, b = 0, c = 3, d = 4, e = 0, f = 6;
//
//	Item* l = ListCreateEmpty();
//	l = ListInsertBack(l, &a);
//	l = ListInsertBack(l, &b);
//	l = ListInsertBack(l, &c);
//	l = ListInsertBack(l, &d);
//	l = ListInsertBack(l, &e);
//	l = ListInsertBack(l, &f);
//
//	MergeInBetweenZeros(l);
//	ListWriteStdout(l);
//}
