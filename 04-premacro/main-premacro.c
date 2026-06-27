/*
 *  02-03-premacro  -  main-premacro.c
 *
 *  Beispiel zum Einsatz von #ifdef
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created on: 24.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>


int main()
{
	printf("Compiler: gcc %s ", __VERSION__);
	printf("compiled on %s at %s\n", __DATE__,__TIME__);
	printf("File: %s  Line: %d\n", __FILE__, __LINE__);
#warning "This is a warning message"
	return 0;
}
