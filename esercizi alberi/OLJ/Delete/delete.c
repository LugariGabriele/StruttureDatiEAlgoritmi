#include "tree.h"
#include <stdbool.h>

Node* DeleteBstNode(Node* n, const ElemType* key) {

    if (n == NULL) return NULL;

    Node* parent = NULL;
    Node* curr = n;

    // Trova il nodo da eliminare e il suo genitore
    while (curr != NULL && ElemCompare(key, &curr->value) != 0) {
        parent = curr;
        if (ElemCompare(key, &curr->value) < 0) // key < valore → cerco a sx
            curr = TreeLeft(curr);
        else                                   // key > valore → cerco a dx
            curr = TreeRight(curr);
    }

    // Nodo non trovato
    if (curr == NULL) return n;

    // CASO 1: nodo da eliminare è foglia (0 figli)
    if (TreeIsLeaf(curr)) {
        if (parent == NULL) {
            // Era la radice
            return NULL;
        }
        // Scollega dal genitore
        if (parent->left == curr) parent->left = NULL;
        else                       parent->right = NULL;
    }

    // CASO 2: nodo da eliminare ha un solo figlio
    else if (curr->left == NULL || curr->right == NULL) {
        Node* child = (curr->left != NULL) ? curr->left : curr->right;
        if (parent == NULL) {
            // Sostituisce la radice
            return child;
        }
        // Ricollega il figlio al genitore
        if (parent->left == curr) parent->left = child;
        else                       parent->right = child;
    }

    // CASO 3: nodo da eliminare ha due figli → usa il PREDECESSORE in-order
    else {
        // cerco predecessore (elemento più a destra di sottoalbero SX)
        Node* pred = curr->left;
        Node* pred_parent = curr;
        while (pred->right != NULL) {
            pred_parent = pred;
            pred = pred->right;
        }

        // Copia il valore del predecessore nel nodo da eliminare
        curr->value = pred->value;

        // Rimuovo il predecessore dalla sua posizione
        Node* pred_child = pred->left;  // il predecessore non ha figlio destro
        if (pred_parent->left == pred)   // pred era figlio SX di pred_parent
            pred_parent->left = pred_child;
        else                             // pred era figlio DX
            pred_parent->right = pred_child;
    }

    return n;
}
