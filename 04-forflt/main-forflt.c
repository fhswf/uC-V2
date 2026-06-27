/*    ______ __    _____      ______         _____
 *   / __/ // /___/ __/ | /| / / __/_____ __/ ___/
 *  / _// _  /___/\ \ | |/ |/ / _//___/ // / /__
 * /_/ /_//_/   /___/ |__/|__/_/      \_,_/\___/
 *
 * Fachhochschule S�dwestfalen
 * Mechatronik/Mikrocomputer
 * Prof. Dr.-Ing. Tobias Ellermeyer
 *
 * Projekt:     02050-forflt
 * Datei:       main-forflt.c
 *
 *  Demonstration Probleme Gleitkomma
 *  bei for-Schleifen
 *
 * Erstellt:    17.09.2019
 * Autor:       Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>   // round()

int main()
{
	double x, inc, endw;
	int32_t cnt,i;
	int32_t endi;

	//--- Schleife mit Gleitkomma ---
	cnt=0;
	endw=45.0;
	inc=0.1;

	for (x=0.0;x<=endw;x+=inc)
	{
		if (x>44.0) // Nur letzte 10 Werte
			{
			printf("(A) %4i: x=%20.16f\n",cnt,x);
			}
		cnt++;
	}

	printf("(A) Durchlaeufe: %i\n",cnt);

	//--- Schleife mit Integer ---
	cnt = 0;
	endi = (long)round(endw/inc);

	for(i=0;i<=endi;i++)
	{
		x=i*inc;
		if (x>44.0) // Nur letzte 10 Werte
			{
			printf("(B) %4i: x=%20.16f\n",cnt,x);
			}
		cnt++;
	 }
	printf("(B) Durchlaeufe: %i\n",cnt);

	return 0;

}
