#include "maxheap.h"
#include <stdio.h>
#include <stdlib.h>

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        return;
    }

    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;

    if (h->size == 0) {
        free(h->data);
        h->data = NULL;
        return;
    }

    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
}

int LastStoneWeight(Heap* h) {

    while (h->size > 1) {
        ElemType y;
        Pop(h, &y);
        ElemType x;
        Pop(h, &x);

        if (ElemCompare(&x, &y) != 0) {
            ElemType new_rock = y - x;
            HeapMaxInsertNode(h, &new_rock);
        }
    }

    return h->size == 0 ? 0 : h->data[0];
}
//
//int main(void) {
//    ElemType v[] = { 77, 21, 18 };
//    Heap* h = HeapCreateEmpty();
//
//    for (size_t i = 0; i < 3; i++) {
//        HeapMaxInsertNode(h, &v[i]);
//    }
//
//    HeapWriteStdout(h);
//
//    int pietra = LastStoneWeight(h);
//    printf("Ultima pietra rimasta: %d\n", pietra);
//
//    HeapDelete(h);
//}
