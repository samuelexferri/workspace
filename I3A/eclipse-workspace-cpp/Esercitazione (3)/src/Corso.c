#include "Corso.h"
#include "Studente.h"

#include <stdio.h>
#include <stdlib.h>

// NodoLista
typedef struct NodoLista {
	studenteRef stud;
	struct NodoLista *next;
} NodoLista;

struct Corso {
	char nomecorso[30];
	NodoLista *listaRef; // Punta al primo nodo in testa alla lista degli studenti iscritti al corso
};

corsoRef makeCorso(char *n) {
	corsoRef cref = malloc(sizeof(struct Corso)); // Ometto l'asterisco perchè corsoRef è già un puntatore

	strcpy(cref->nomecorso, n);

	cref->listaRef = NULL; // Inizialmente la lista non ha nodi

	return cref;
}

// Inserimento in testa alla lista
void addStudente(corsoRef c, studenteRef s) {
	NodoLista *nodo = malloc(sizeof(struct NodoLista)); // Uso l'asterisco

	nodo->stud = s;
	nodo->next = c->listaRef;
	c->listaRef = nodo;
}

void printCorso(corsoRef c) {
	printf("%s: ", c->nomecorso);

	NodoLista *point = c->listaRef;

	while (point != NULL) {
		printf("%s, ", point->stud);
		point = point->next;
	}

	printf("\n");
}
