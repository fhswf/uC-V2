/*
 *  03-09-proto1  -  main-proto1.c
 *
 *  Verwendung von Funktionen mit Prototypen (Teil 1)
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

// Prototyp
int max(int,int);

// Hauptroutine
int main()
{
	int a,b;
	a=5;
	b=7;
	printf("max(%i,%i)=%i\n",a,b,max(a,b));
	return 0;
}

// Die folgende Zeile aktiviert den etwas kompakteren Code
//#define CRYPTIC

int max(int x, int y)
{
#ifndef CRYPTIC
	int m;

	if (x>y)
	{
		m=x;
	}
	else
	{
		m=y;
	}
	return(m);
#else
	// Sehr kompakt, aber hier muss man schon fit in C sein ;-)
	return (x>y)?x:y;
#endif
}
