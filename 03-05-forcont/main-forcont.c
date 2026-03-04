/*
 *  03-05-forcont  -  main-forcont.c
 *
 * 	Anwendungsbeispiel for-Schleife mit continue-Anweisung
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */


#include <stdio.h>
#include <stdint.h>

int main()
{
	for (uint8_t i=0;i<10;i++)
	{
		printf("* ");
		if (i%2) continue;
		printf("%i ",i);
	}
return 0;

}
