/*
 *  03-03-for  -  main-for.c
 *
 *  Anwendung von for-Schleifen und
 *  typische Fehler bei for-Schleifen (z.B. Überlauf, falsche Schrittweite, falscher Vergleichsoperator)
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	uint16_t i;

	// Hochzaehlen von 0...9
	for (i=0;i<10;i++)
	{
		printf("%" PRIu16 ", ",i);
	}
	printf("\n");



	// Hochzaehlen von 0...9 in 3-er Schritten
	for (i=0;i<10;i=i+2)
	{
		printf("%" PRIu16 ", ",i);
	}
	printf("\n");


	// Runterzaehlen von 10...1 in 3-er Schritten
	for (int16_t j=10;j>0;j-=3)
	{
		printf("%" PRId16 ", ",j);
	}
	printf("\n");

	for (int16_t j=32;j>0;j>>=1)
	{
		printf("%" PRId16 ", ",j);
	}
	printf("\n");

	printf("Böser Fehler ;-)\n");
	for (i=10;i>0;i-=3)
	{
		printf("%" PRIu16 ", ",i);

		// Escape, um aus "bösem" Fehler zu entkommen
		if ((i>20) && (i<65500)) break;
	}
	printf("\n");

	// Noch ein böser Fehler:
	// Hochzaehlen von 0...999 mit uint8_t - Achtung: Überlauf-
	i=0;
	for (uint8_t k=0;k<1000;k++)
	{
		printf("%i ",k);
		if (i++>260) break;	// Rettungsanker
	}



	return 0;
}
