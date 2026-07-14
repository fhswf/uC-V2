/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     12-16-zeigfeld
 * Datei:       main-zeigfeld.c
 *
 * Erstellt:    02.10.2019
 * Überarbeitet: 03.07.2026
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>

int main()
{
	int werte[5]={2,3,5,7,11};
	int *wertez;
	int i;

	wertez=werte;

	for (i=0;i<5;i++)
	{
	   printf("wertez=0x%p; werte[i]=%2i; *wertez=%2i\n",
		  (void*)wertez, werte[i], *wertez);
	   //wertez++;
	   //wertez=wertez+2;
	   wertez = (int*)( (char*)wertez +1);
	}
}
