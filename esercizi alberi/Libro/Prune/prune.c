#include "tree.h"

Node* TreePrune(Node* t, const ElemType* cut_value) {

	/*
	input albero binario qualunque tipo,t e un cut value.
	funz deve scorrere ed eliminare, liberando memoria e aggiornando opportunamente
	i puntatori, tutti i sottoalberi aventi radice uguale cut_value.
	*/

	if (TreeIsEmpty(t)) return TreeCreateEmpty();

	// se radice corrente è da tagliare cancella tutti i sottoalberi
	if (ElemCompare(TreeGetRootValue(t), cut_value) == 0)
	{
		TreeDelete(t); //cancella tutto il sottoalbero
		return NULL; // così non scorro ulteriorente per di qua
	}


	t->left = TreePrune(TreeLeft(t), cut_value);
	t->right= TreePrune(TreeRight(t), cut_value);

	return t;
}

int main(void) {

    Node* t = TreeCreateRoot(&(ElemType) { 2 },
        TreeCreateRoot(&(ElemType) { 3 },
            TreeCreateRoot(&(ElemType) { 4 },
                TreeCreateRoot(&(ElemType) { 8 }, NULL, NULL),
                TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL)
            ),
            NULL
        ),
        TreeCreateRoot(&(ElemType) { 7 },
            NULL,
            TreeCreateRoot(&(ElemType) { 4 },
                TreeCreateRoot(&(ElemType) { 0 }, NULL, NULL),
                TreeCreateRoot(&(ElemType) { 1 }, NULL, NULL)
            )
        )
    );

    t = TreePrune(t, &(ElemType){4});

    TreeWriteStdoutInOrder(t);

    TreeDelete(t);
    return 0;
}
