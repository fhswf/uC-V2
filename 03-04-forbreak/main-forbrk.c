/*
 *  03-04-forbreak  -  main-forbrk.c
 *
 * 	Anwendungsbeispiel for-Schleife mit break-Anweisung
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <stdint.h>

int main()
{
int16_t tabelle[]={5,3,8,7,11,32,12,43,21};
int16_t i, wert;
int16_t N;  // Anzahl Werte in Tabelle


// Anzahl Werte in Tabelle
N = sizeof(tabelle)/sizeof(int16_t);

wert = 321;   // Suche, ob Wert 32 in Array vorkommt

for(i=0;i<N;i++) // In Tabelle nach wert suchen
{
   if (tabelle[i]==wert) break;
}
if (i<N) // Wenn i<N, dann wurde vorher abgebrochen, d.h. gefunden
{
   printf("Wert an Position %i gefunden!\n",i);
}
else
{
   printf("Wert NICHT gefunden!\n");
}

return 0;

}
