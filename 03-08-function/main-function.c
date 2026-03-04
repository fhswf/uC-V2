/*
 *  03-08-function  -  main-function.c
 *
 *  Eine einfache Funktion zur Berechnung der Oberflaeche eines Zylinders
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>


float zylinder_oberflaeche(float h, float r)
	{
		float o;
		o=2.0*3.141*r*(r+h);
		return(o);
	}

int main()
{
	float x;

	x= zylinder_oberflaeche(5.0,2.0);
	printf("Zylinderoberflaeche %5.2f\n", x);

	// Auch moeglich:
	printf("Zylinderoberflaeche %5.2f\n", zylinder_oberflaeche(5.0,2.0));
	return 0;
}
