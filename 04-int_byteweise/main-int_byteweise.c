/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     03050-zeigfeld
 * Datei:       main-zeigfeld.c
 *
 * Erstellt:    02.10.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>

int main()
{
	int werte=0x13247A8B;
	unsigned char *wertez;
	int i;

	wertez=(unsigned char*)&werte;

	for (i=0;i<4;i++)
	{
		printf("*wertez= 0x%p  (*wertez) = 0x%02x\n",
				wertez,*wertez);
		wertez++;
	}
}
