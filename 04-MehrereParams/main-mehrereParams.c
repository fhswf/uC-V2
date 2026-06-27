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

void func1(int *x, int *y)
{
	int h;
/*	h = (*x);
	(*x) = (*y);
	(*y) = h;
	*/
	(*x) = 10;
	(*y) = 20;
}

int main()
{
	int a,b;
//	a=2;
//	b=3;

	func1(&a,&b);
	printf("a=%i b=%i\n",a,b);
}
