#include "no_cycle.h"




void RemoveCycle(Item* i) {
	
	if (ListIsEmpty(i))
	{
		return;
	}

	//creo due puntatori e li faccio scorrere, uno lo faccio andare più veloce e se c'è un ciclo allora ad un certo punto di sovrappongono

	Item* slow = i;
	Item* fast = i;

	while (!ListIsEmpty(fast)) { // se non hanno cicli arrivaranno a null

		slow = slow->next;
		fast = fast->next->next;

		if (slow==fast) // trovato ciclo
		{

			//cerco inizio ciclo(ultimo nodo prima di iniziare loop)
			Item* start = i;
			while (start != slow) {
				start = start->next;
				slow = slow->next;
			}

			// cerco ultimo nodo prima del ciclo
			Item* last = start;
			while (last->next != start) {
				last = last->next;
			}

			// metto ultimo nodo del ciclo come ultimo della lista(lo stacco dal ciclo)
			last->next = NULL;
			return;
		}
	}
}
