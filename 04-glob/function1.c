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
 * Datei:       function1.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

static int16_t a=1;

void function1()
{
	printf("(F) a=%i\n",a);
	a=a+1;
}
