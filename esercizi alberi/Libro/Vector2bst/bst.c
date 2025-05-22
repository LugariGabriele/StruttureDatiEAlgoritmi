#include "tree.h"


Node* InsertBst(Node* root, const ElemType* e) {

    if (root==NULL) // sono arrivato dove dovrei?
    {
        return TreeCreateRoot(e, NULL, NULL); // creo il nodo 
    }
    
    if (ElemCompare(e,TreeGetRootValue(root))<0) // e minore
    {
        root->left = InsertBst(root->left, e);
    }
    else if (ElemCompare(e, TreeGetRootValue(root)) > 0)
    {
        root->right = InsertBst(root->right, e);

    }


    return root;
}


Node* Vector2Bst(const ElemType* v, size_t v_size) {

    if (v == NULL || v_size == 0) {
        return TreeCreateEmpty();
    }

    Node* root = TreeCreateRoot(&v[0], NULL, NULL);
    for (size_t i = 1; i < v_size; ++i)
    {
        InsertBst(root, &v[i]);
    }

    return root;
}

int main(void) {

    ElemType v[] = { 8, 2, 4, 5, 2, 1, 9 };
    size_t size = sizeof(v) / sizeof(ElemType);

    Node* tree = Vector2Bst(v, size);

    TreeWriteStdoutPreOrder(tree);  // 8 2 1 4 5 9 
    printf("\n");

    TreeDelete(tree);
    return 0;
}