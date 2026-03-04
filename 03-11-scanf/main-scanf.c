/*
 *  03-11-scanf  -  main-scanf.c
 *
 *  Demonstration der Verwendung von scanf für die Eingabe
 *  von Double-Zahlen und Text
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */


#include <stdio.h>

int main(void)
{
   double x;

   printf("Geben Sie einen Wert fuer x ein:");
   scanf("%lf",&x);

   printf("Sie haben x=%5.2lf eingegeben\n", x);

   char eingabe[20];
   printf("Text:");
   scanf("%19s",eingabe);
   printf("Sie haben '%s' eingegeben\n", eingabe);
   return 0;
}

