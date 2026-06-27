/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02130-static-func
 * Datei:       modul.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

static int16_t berechnung(int16_t x);	// Prototyp

int16_t function1(int16_t wert)
{
	printf("(F) wert=%i\n",wert);
	return berechnung(wert);
}

static int16_t berechnung(int16_t x)
{
	int16_t hilf;

	hilf=x*x+x;	// Nur zu Demo-Zwecken, ist sinnfrei...
	return(hilf);
}
