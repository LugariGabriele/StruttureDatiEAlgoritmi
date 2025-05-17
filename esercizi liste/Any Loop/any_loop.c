#include "list.h"
#include <stdbool.h>

bool AnyLoop(const Item* i) {

	if (ListIsEmpty(i))
	{
		return false;
	}

	// faccio muovere due puntatori sulla stessa lista ma uno lo faccio andare più veloce, se non ci sono loop il veloce arriverà a null invece
	//ci sono loop fast prima o poi raggiungerà slow (posso controllare anche solo se arrivo a null ma probabile entro in ciclo infinito)
	Item* slow = i;
	Item* fast = i->next;

	while (fast != NULL && fast->next != NULL) {
		if (slow == fast)
		{
			return true;
		}

		slow = slow->next;
		fast = fast->next->next; // avanzo di due nodi alla volta
	}
	return false;

}
