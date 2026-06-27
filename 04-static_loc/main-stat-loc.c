/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02110-static-loc
 * Datei:       main-stat-loc.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>


int16_t summe(int16_t wert)
{
	static int16_t s=0;
	s = s+wert;
	return s;
}

int main()
{
	int16_t i;

	for (i=0;i<5;i++)
	{
		printf("(%i)=>%i\n",i,summe(i));
	}
}


