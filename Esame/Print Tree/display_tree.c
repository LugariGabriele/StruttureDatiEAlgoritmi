#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
bool StampoNull(const Node* t) {

	if (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t))) // entrambi null
	{
		return false;
	}

	return true;
}

void Print(const Node* t, int idx, const Node* parent) {
	if (idx == 0)
	{
		printf("%d", *TreeGetRootValue(t)); // radice
	}

	if (TreeIsEmpty(t))
	{
		if (StampoNull(parent))
		{
			if (idx>1)
			{
				printf("+");
			}
			for (int i = 0; i < idx - 1; i++)
			{
				printf("    ");

			}

			printf("+--");
			printf(" NULL");
			printf("\n");

		}

		return;
	}

	if (idx > 0)
	{
		if (idx>1)
		{
			printf("+");

		}
		
		for (int i = 0; i < idx - 1; i++)
		{
			printf("   ");

		}

		printf("+--");
		printf(" %d", *TreeGetRootValue(t));
	}

	printf("\n");
	Print(t->left, idx + 1, t);
	Print(t->right, idx + 1, t);

}


void DisplayTree(const Node* t) {

	if (TreeIsEmpty(t))
	{
		return;
	}

	Print(t, 0, NULL);
}


//int main(void)
//{
//	{
//		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//		Node* t = TreeCreateRoot(&e[5],
//			TreeCreateRoot(&e[2],
//				TreeCreateRoot(&e[1], NULL, NULL),
//				TreeCreateRoot(&e[3],
//					NULL,
//					TreeCreateRoot(&e[4], NULL, NULL))),
//			TreeCreateRoot(&e[6], NULL, NULL));
//		//Chiamata a funzione
//		DisplayTree(t);
//	}
//}
//	{
//		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//		Node* t = TreeCreateRoot(&e[5],
//			TreeCreateRoot(&e[2],
//				TreeCreateRoot(&e[1], NULL, NULL),
//				NULL),
//			TreeCreateRoot(&e[6], NULL, NULL));
//		 Chiamata a funzione
//	}
//	{
//		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//		Node* t = TreeCreateRoot(&e[3], TreeCreateRoot(&e[2], TreeCreateRoot(&e[1], TreeCreateRoot(&e[0], NULL, NULL), NULL), NULL), NULL);
//		 Chiamata a funzione
//	}
//	{
//		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
//		Node* t = TreeCreateRoot(&e[12],
//			TreeCreateRoot(&e[6],
//				TreeCreateRoot(&e[5],
//					TreeCreateRoot(&e[3],
//						NULL,
//						NULL),
//					NULL),
//				TreeCreateRoot(&e[9],
//					TreeCreateRoot(&e[8], NULL, NULL),
//					TreeCreateRoot(&e[10], NULL, NULL))),
//			TreeCreateRoot(&e[15],
//				TreeCreateRoot(&e[13], NULL, NULL),
//				TreeCreateRoot(&e[18], NULL, NULL)));
//		 Chiamata a funzione
//	}
//
//	return 0;
//}