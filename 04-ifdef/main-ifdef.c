/*
 *  02-02-ifdef  -  main-ifdef.c
 *
 *  Beispiel zum Einsatz von #ifdef
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created on: 24.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

#define PI 3.1415927

#define DEBUG	// De

int main()
{
	double u,r;
	r = 3.0;
	u = 2.0*PI*r;
#ifdef DEBUG
	printf("r=.2lf  u=.2lf\n");
#endif
	// ... weitere Berechnungen ...
	printf("Fertig\n");
	return 0;
}
