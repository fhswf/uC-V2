/*
 *  03-13-bufover  -  main-bufover.c
 *
 *  Demonstratinon von Buffer Overflow, der Variablen überschreibt
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created/updated on: 26.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>


int main()
{
	   int  i = 10;
	   char buf[6];
	   printf("Text fuer buf[6]=");
	   fflush(stdout); // Nur fuer Eclipse-Console
	   scanf("%s",buf);
	   printf("buf=%s\n",buf);
	   printf("i=%i\n",i);

	   printf("Adresse von buf=%p\n",(void*)buf);
	   printf("Adresse von i=%p\n",(void*)&i);

	   /*
	   int x[10]={0};

	   i=11;
	   x[i] = 20;		// i liegt hier ausserhalb des erlaubten
	   					// Bereichs 0-9
	   	   	   	        // Address-Sanitizer wuerde hier einen Fehler melden, da i zu gross ist
	   	   	   	        // -fsanitize=address (ist aber mit mingw nicht so einfach zu verwenden)
	   printf("x[0] %i\n",x[0]);
	   */
	   return 0;
}
