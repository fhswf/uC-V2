/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     03020-zeiger2
 * Datei:       main-zeiger2.c
 *
 * Erstellt:    02.10.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>


int main()
{
	short int a;
	short int *za;
	a=77;
	za = &a;
	printf("Der Zeiger za weist auf die Adresse 0x%p\n",
			(void*)za);
	printf("An dieser Adresse ist der Wert %i gespeichert\n",*za);
	printf("Die Adresse, unter der za gespeichert ist: 0x%p\n",(void*)&za);

	return 0;
}
