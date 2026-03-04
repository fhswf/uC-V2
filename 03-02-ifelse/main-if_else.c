/*
 *  02-05-if_else  -  main-if_else.c
 *
 *  Beispiel zum Einsatz if/else-Abfragen
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created on: 24.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

int main()
{
	double x;

	// Eingabe des Wertes
	printf("Eingabe x:");
	fflush(stdout);  // Nur noetig, falls in Eclipse-Command-Window
	                 // Ausgabebuffer leeren (sonst erscheint Text "Eingabe x:" nicht)
	scanf("%lf",&x); // Eingabe x (folgt spaeter in Vorlesung ...)


	if (x<0.0) printf("x ist kleiner als 0.0\n");
	else printf("x ist gößer gleich 0.0\n");


	printf("\n\nBeispiel 1: Verschachtelte if/else\n");

	if (x>=10.0) {
		printf("10 <= x\n");
	}
	else {
		if (x>0.0) {
			printf("0.0 < x < 10.0\n");
		}
		else {
			printf("x <= 0.0\n");
		}
	}

	// Einzelne if-Abfragen
	printf("\nBeispiel 2: Einzelne If-Abfragen fuer Bereiche\n");

	if (x==10.0) {
		printf("10 <= x\n");
	}
	if ( (x>0.0) && (x<10.0) ) {
		printf("0.0 < x < 10.0\n");
	}
	if (x<=0.0)	{
		printf("x <= 0.0\n");
	}


	printf("\nUnd hier so oder so gehts weiter x=%lf...\n",x);
	return 0;
}
