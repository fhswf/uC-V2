/*
 *  03-10-proto2  -  max.c
 *
 *  Ausgelagerte max() Funktion
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

#include "max.h"

short max(short x, short y)
{
	int m;

	if (x>y)
	{
		m=x;
	}
	else
	{
		m=y;
	}
	printf("Fertig in max\n");
	return(m);
}

