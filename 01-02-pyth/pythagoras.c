/*
 *  01-02-pyth  -  pythagoras.c
 *
 *  Berechnung des Satz von Pythagoras
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c;

	a=3.5;
	b=4.0;
	// sqrt => Square Root => Quadratwurzel
	// pow  => Power of => Potenz

	c= sqrt(a*a+pow(b,2));
	printf("Pythagoras\n");
	printf("a= %lf\n",a);
	printf("b= %lf\nc= %lf\n",b,c);
	return 0;
}
