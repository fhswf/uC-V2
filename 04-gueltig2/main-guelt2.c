/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule S�dwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02090-gueltig2
 * Datei:       main-guelt2.c
 *
 * Erstellt:    18.09.2019
 * Autor:       Tobias Ellermeyer
 */
#include <stdio.h>
#include <stdint.h>


// HINWEIS: Je nach dem, was getestet werden soll,
// Variablendeklarationen entsprechend auskommentieren...

int16_t a=2;

void add_a()
{
	int16_t a;
	printf("(F) a=%i\n",a);
	a=a+1;
}

int main()
{
    int16_t a=20;
	printf("(1) a=%i\n",a);
	add_a();
	printf("(2) a=%i\n",a);
	a=a+2;
	add_a();
	printf("(3) a=%i\n",a);
	return 0;

}


