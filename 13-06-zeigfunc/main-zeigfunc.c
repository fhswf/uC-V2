/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule Südwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     13-06-zeigfunc
 * Datei:       main-zeigfunc.c
 *
 * Erstellt:    07.07.2026
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>

int summe(int n)
{
	static int sum=0;
	sum=sum+n;
	return sum;
}

int mult(int n)
{
	static int mult=1;
	mult=mult*n;
	return mult;
}


int main()
{
	int (*calc)(int);
	char erg[2];
	printf("1: Summe bilden\n");
	printf("2: Produkt bilden\n");
	scanf("%1s",erg);
	switch(erg[0])
	{
		case '1':
			calc=&summe;
			break;
		case '2':
			calc=&mult;
			break;
		default:
			printf("Falsche Eingabe\n");
			return 1;
	}

	printf("Ausgewaehlte Funktion: %s\n",erg);
	for(int i=1;i<=5;i++)
	{
		printf("calc(%i)=%i\n",i,calc(i));
	}

}
