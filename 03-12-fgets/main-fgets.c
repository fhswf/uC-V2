/*
 *  03-12-fgets  -  main-fgets.c
 *
 *  fgets statt scanf verwenden, um Whitespace-Zeichen (z.B. Leerzeichen) in der Eingabe zu erlauben
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
   char eingabe[20];
   printf("Text:");
   //scanf("%19s",eingabe);
   fgets(eingabe,19,stdin);
   eingabe[strlen(eingabe)-1]='\0'; // Zeilenumbruch entfernen
   printf("Sie haben '%s' eingegeben\n", eingabe);
   return 0;
}

