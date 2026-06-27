/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule S�dwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02100-extern
 * Datei:       function1.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

// TEST

#include <stdio.h>
#include <stdint.h>

int16_t a;

void function1()
{
	printf("(F) a=%i\n",a);
	a=a+1;
}
