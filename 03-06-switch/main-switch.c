/*
 *  03-06-switch  -  main-switch.c
 *
 * Einfaches Beispiel fuer switch/case-Anweisung
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
	int note;

	printf("Note eingeben (1-6):");
	scanf("%i",&note);
	switch(note)
	{
	case 1: printf("sehr gut\n");
			break;
	case 2: printf("gut\n");
			break;
	case 3: printf("befriedigend\n");
			break;
	case 4: printf("ausreichend\n");
			break;
	case 5: printf("mangelhaft\n");
			break;
	case 6: printf("ungenuegend\n");
			break;
	default: printf("Ungueltige Note\n");
			 break;
	}
	return 0;
}


