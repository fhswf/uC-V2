/*
 *  02-02-inttypes  -  main-inttypes.c
 *
 *  Verwendung von Längenmodifizierern und
 *  inttypes.h für portable Ganzzahltypen
 *
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int main()
{
	uint8_t a = 100;

	printf("uint8_t a = %u\n", a);
//	scanf("%u",&a);  // richtig %hhu
	scanf("%hhu",&a);

	printf("a = %" PRIu8 "\n", a);   // richtig PRIu8
	scanf("%" SCNu8, &a); 			 // richtig SCNu8

	return 0;
}
