#include "elemtype.h"
#include "list.h"
#include <string.h>

#include <stdbool.h>


//const ElemType* Find(const Item* i, const char* name) {
//
//
//	while (!ListIsEmpty(i)) {
//
//		ElemType* e = ListGetHeadValue(i);
//		if (strcmp(e->name, name) == 0)
//		{
//			return e;
//		}
//
//		i = ListGetTail(i);
//	}
//	return NULL;
//}

Item* Delete(Item* i, const char* name) {


	if (i == NULL) {
		return NULL;
	}

	// Caso speciale: eliminare il primo nodo
	if (strcmp(ListGetHeadValue(i)->name, name) == 0) {
		Item* temp = i;
		i = i->next;
		ElemDelete(&temp->value);
		free(temp);
		return i;
	}

	Item* prev = i;
	Item* curr = i->next;

	while (curr != NULL) {
		if (strcmp(ListGetHeadValue(curr)->name, name) == 0) {
			prev->next = curr->next;
			ElemDelete(&curr->value);
			free(curr);
			return i;
		}
		prev = curr;
		curr = curr->next;
	}

	return i;
}
//
//extern Item* Sort(Item* i) {
//
//	if (ListIsEmpty(i) || ListIsEmpty(ListGetTail(i))) {
//		return i; // Lista vuota o con un solo elemento: già ordinata
//	}
//
//	bool ordinata = false;
//
//	while (!ordinata) {
//
//		ordinata = true;
//		Item* curr = i; // ci serve per non modificare puntatore a testa di i(modifico usando curr ma il puntatore i rimane fermo)
//
//		while (!ListIsEmpty(curr) && !ListIsEmpty(curr->next)) {
//			if (ElemCompare(&curr->value, &curr->next->value) > 0) // val> vall sucessivo
//			{
//				ElemSwap(&curr->value, &curr->next->value);
//				ordinata = false;
//			}
//			curr = curr->next; // scorro lista
//		}
//	}
//
//	return i;
//}
//
//Item* Filtra(const Item* i, const char* city) {
//
//	Item* lista_filtrata = ListCreateEmpty();
//
//	while (!ListIsEmpty(i)) {
//
//		const	ElemType* e = ListGetHeadValue(i);
//		if (ElemCompare(e->city, city) == 0)
//		{
//			lista_filtrata = ListInsertBack(lista_filtrata, e);
//		}
//
//		i = ListGetTail(i);
//	}
//
//	return lista_filtrata;
//}
//
//
//Item* Reverse(const Item* i) {
//	Item* lista_inversa = ListCreateEmpty();
//
//	while (!ListIsEmpty(i)) {
//
//		ElemType* e = ListGetHeadValue(i);
//		lista_inversa = ListInsertHead(e, lista_inversa);
//
//		i = ListGetTail(i);
//	}
//
//	return lista_inversa;
//}
//
//
//Item* Append(const Item* i1, const Item* i2) {
//
//	Item* lista_append = ListCreateEmpty();
//
//	while (!ListIsEmpty(i1)) {
//		ElemType* e = ListGetHeadValue(i1);
//		lista_append = ListInsertBack(lista_append, e);
//
//		i1 = ListGetTail(i1);
//	}
//
//	while (!ListIsEmpty(i2)) {
//		ElemType* e = ListGetHeadValue(i2);
//		lista_append = ListInsertBack(lista_append, e);
//
//		i2 = ListGetTail(i2);
//	}
//
//
//	return lista_append;
//}
//
//Item* AppendMod(Item* i1, Item* i2) {
//	// append senza creare nuova lista
//
//	if (ListIsEmpty(i1)) {
//		return i2; // i1 è vuota, ritorno direttamente i2
//	}
//
//
//	Item* curr = i1;
//	while (curr->next != NULL) {
//		curr = curr->next; // sposto puntatore a fine di i1
//	}
//
//	curr->next = i2; // aggiungo seconda lista
//	return i1;
//}




//
//
//int main(void) {
//	// Creazione indirizzi
//	ElemType addr1 = {
//		"Mario Rossi", "Via Roma", 10, "Milano", "MI", "20100"
//	};
//	ElemType addr2 = {
//		"Luigi Verdi", "Corso Italia", 25, "Torino", "TO", "10100"
//	};
//	ElemType addr3 = {
//		"Anna Bianchi", "Via Milano", 3, "Genova", "GE", "16100"
//	};
//	ElemType addr4 = {
//		"Mario Rossi", "Via Napoli", 15, "Napoli", "NA", "80100"
//	};
//
//	// Creazione lista
//	Item* list = ListCreateEmpty();
//	list = ListInsertBack(list, &addr1);
//	list = ListInsertBack(list, &addr2);
//	list = ListInsertBack(list, &addr3);
//	list = ListInsertBack(list, &addr4);
//
//	printf("Rubrica:\n");
//	ListWriteStdout(list);
//
//	// Ricerca
//	const char* nome_cercato = "Mario Rossi";
//	const ElemType* trovato = Find(list, nome_cercato);
//
//	printf("\nRisultato della ricerca per \"%s\":\n", nome_cercato);
//	if (trovato != NULL) {
//		ElemWriteStdout(trovato);
//	}
//	printf("\n");
//
//	const Item* elimina = Delete(list, "Luigi Verdi");
//	printf("lista con elimina:\n");
//	ListWriteStdout(elimina);
//	printf("\n");
//
//
//	Item* list_sort = Sort(list);
//
//	printf("\nLista ordinata:\n");
//	ListWriteStdout(list_sort);
//
//
//	const char* citta_cercata = "Milano";
//	Item* lista_filtrata = Filtra(list, citta_cercata);
//
//	printf("\nIndirizzi nella città di %s:\n", citta_cercata);
//	ListWriteStdout(lista_filtrata);
//
//	ListDelete(lista_filtrata);
//
//
//	Item* lista_revrese = Reverse(list);
//
//	printf("\nLista invertita:\n");
//	ListWriteStdout(lista_revrese);
//
//	ListDelete(lista_revrese);
//
//
//	Item* l2 = ListCreateEmpty();
//	ElemType a = { "Paolo Verdi", "Via Napoli", 3, "Roma", "RM", "00100" };
//	ElemType b = { "Lucia Bianchi", "Via Milano", 2, "Torino", "TO", "10100" };
//
//	l2 = ListInsertBack(l2, &a);
//	l2 = ListInsertBack(l2, &b);
//
//
//	Item* concatenata = Append(list, l2);
//
//	printf("Lista concatenata:\n");
//	ListWriteStdout(concatenata);
//
//	ListDelete(concatenata);
//
//	Item* concatenata_mod = AppendMod(list, l2);
//	printf("\nLista concatenata Mod:\n");
//	ListWriteStdout(concatenata_mod);
//
//	ListDelete(concatenata_mod);
//
//}
//
//
