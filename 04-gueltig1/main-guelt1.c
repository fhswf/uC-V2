/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule S�dwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02080-gueltig1
 * Datei:       main-guelt1.c
 *
 * Erstellt:    18.9.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

int main()
{
	int16_t i=100, b=0;

	printf("(1) i=%i  b=%i\n",i,b);

	for (int16_t i=0;i<2;i++)
	{
		b++;
		printf("(2) i=%i  b=%i\n",i,b);
	}
	printf("(3) i=%i  b=%i\n",i,b);
	return 0;
}

