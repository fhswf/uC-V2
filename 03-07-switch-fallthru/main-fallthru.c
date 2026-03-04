/*
 *  03-07-switch-fallthru  -  main-falltrhu.c
 *
 *  Beispiel fuer switch/case-Anweisung mit Fall-Through (kein break)
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

	for (i=0;i<5;i++)
	{
		printf("\n---i=%i---",i);
		switch(i)
		{
		case 0: printf("Marke 0 ");	// fall through
		case 1: printf("Marke 1 ");
				[[fallthrough]];
		case 2: printf("Marke 2 ");
				break;
		case 3: printf("Marke 3 ");
				break;
		default: printf("Default ");
				break;
		}
	}
	return 0;
}


