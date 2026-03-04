/*
 *  03-10-proto2  -  main-proto2.c
 *
 *  Prototypen und Module in exernen Dateien (Teil 2)
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

#include "max.h"

// Hauptroutine
int main()
{
	int a,b;
	a=5;
	b=7;
	printf("Maximum(%i,%i)=%i\n",a,b,max(a,b));
	return 0;
}


