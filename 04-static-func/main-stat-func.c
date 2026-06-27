/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02120-static-glob
 * Datei:       main-stat-glob.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

#include "modul.h"


int main()
{
	int16_t a,b;
	a=12;
	b=function1(a);
	printf("(M1) b=%i\n",b);
	//b=berechnung(a);  // Geht nicht, da static
	return 0;
}


