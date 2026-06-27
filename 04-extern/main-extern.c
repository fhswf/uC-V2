/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02100-extern
 * Datei:       main-extern.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

void function1();  // Prototyp

int16_t a;			// globale Variable


int main()
{
	a=12;
	printf("(M1) a=%i\n",a);
	function1();
	printf("(M2) a=%i\n",a);
	return 0;
}


