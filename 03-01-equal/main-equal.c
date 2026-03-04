/*
 *  03-01-equal  -  main-equal.c
 *
 *  Typischer Fehler bei if equal Abfragen
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

int main()
{
	int i;

	i=3;

//	if (5==i)		// Ergibt Fehler, wenn versehentlich (5=i) geschrieben wird, da 5 eine Konstante ist und nicht zugewiesen werden kann
	if (i=5)		// Wenn eine Zuweistung stattfinden soll, müsste dort ((i=5)) stehen, damit kein Warning auftritt
	{
		printf("i ist 5\n");
	}
	printf("Wert von i: %i\n",i);
	return 0;
}
