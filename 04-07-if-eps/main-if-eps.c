/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule S�dwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02040-if-eps
 * Datei:       main-if-eps.c
 *
 *  Demonstration Probleme Gleitkomma if-Abfrage auf Gleichheit
 *
 * Erstellt:    17.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <math.h>		// fuer fabs()

#define EPSILON 1.0e-10

int main()
{

	double a,b,x;

	a = 0.8;	// 0.7+1.0 funktioniert ...
	b = 0.9;

	double a=0.8, b=0.9,x;
	x = a + b;

	//---- Normale if-Abfrage ----
	if (x==1.7)
	{
		printf("(A) x==1.7\n");
	}
	else
	{
		printf("(A) x!=1.7 (%20.17lf)\n",x);
	}

	//---- if-Abfrage mit Epsilon----
	if (fabs(x-1.7) < EPSILON)
	{
		printf("(B) x==1.7\n");
	}
	else
	{
		printf("(B) x!=1.7\n");
	}
}


