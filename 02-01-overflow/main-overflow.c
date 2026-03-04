/*
 *  02-01-overflow  -  main-overflow.c
 *
 *  Überlauf (Overflow) bei Ganzzahlen
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int8_t t,r;
	int32_t a,b,c,w;
    t = 126;
    t = t +2;
    printf("(1) t=%" PRId8 "\n",t);   // PRId8 ist das Format für int8_t, damit wird die Ausgabe korrekt interpretiert

	r=-126;
	r=r-3;
	printf("(2) r=%" PRId8 "\n",r);

	r=-126-3;		// Warning bei Konstanten

	a=1000000;
	b=2000000;
	c=b;
	w=a*b/c;
	printf("(3) w=%i\n",w);
	w=a*b;
	printf("(3b) ab=%i /c=%i\n",w,w/c);
	a=1000000;
	b=2000000;
	w=a*b/b;
	printf("(4) w=%i\n",w);

	uint8_t i;

	for (i=10;i>=0;i--)
	{
		printf("%i\n",i);
		if (i==200) break;	// Rettungsanker
	}


}


