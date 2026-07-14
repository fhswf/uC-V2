/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     13-03-zeiger3
 * Datei:       main-zeiger3.c
 *
 * Erstellt:    02.10.2019
 * Überarbeitet: 03.07.2026
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>


int main()
{
	short int a;
	short int *za;
	a=77;
	za = &a;
	printf("(1)  a=%i\n",a);
	(*za)=(*za)+5;		// Zugriff über Zeiger
	printf("(2)  a=%i\n",a);
	a=a+11;				// Direkter Zugriff
	printf("(3)  a=%i\n",a);

	return 0;
}
