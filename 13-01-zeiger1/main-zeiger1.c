/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     13-01-zeiger1
 * Datei:       main-zeiger1.c
 *
 * Erstellt:    02.10.2019
 * Update:	    03.07.2026
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

int main()
{
	int16_t a;
	int16_t *za;
	a=77;
	za = &a;

	printf("Die Variable a hat den Wert %i\n",a);
	printf("und ist unter der Adresse 0x%p gespeichert\n",(void *)&a);
	printf("Der Zeiger za weist auf die Adresse 0x%p\n", (void *)za);
	printf("An dieser Adresse ist der Wert %i gespeichert\n",*za);

	return 0;
}
