#include "tree.h"
#include<stdbool.h>
#include <stdlib.h>

bool TreesAreTwins(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}

	// Uno è vuoto, l'altro no => non sono gemelli
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}


	bool leftOk = TreesAreTwins(TreeLeft(t1), TreeLeft(t2));
	bool rightOk = TreesAreTwins(TreeRight(t1), TreeRight(t2));

	return leftOk && rightOk;
}