/************************************
 *
 * File Name:  main.c
 * Path:       /01-01-steuer/main.c
 * Created on: 14.02.2026
 * Author:     tobi
 *
 * Praktikum uC
 *
 ************************************/

#include <stdio.h>
#include<time.h>

void delay(unsigned int millis);

int main(void) {
	printf("Nur neue Zeile\nweiterer Text\n");
	printf("Mit Carriage Return\r\nweiterer Text\n\n");	// Unter Windows identisch ...
	printf("Tab1\tTab2\t*\n");
	printf("Halle\tWolrd\t*\n\n");
	printf("Hallo\\b\\b\\b\\bello\n");
	printf("Hallo\b\b\b\bello\n");

	// Fortschrittsanzeige mit Backspace ...
	printf("  0 %%");
	for (int i = 0; i <= 100; i+=5) {
		printf("\b\b\b\b\b%3i %%", i);
		fflush(stdout);	// Ausgabe sofort erzwingen
		delay(100);	// 100 ms warten
	}

	printf("Fertig!\n\n");

	// Beep (funktioniert nicht in allen Terminals)
	printf("\a");

	return 0;
}

// Einfache Implementierung einer delay-Funktion,
// die auf der clock-Funktion basiert
void delay(unsigned int millis)
{
    clock_t goal = millis + clock();
    while (goal > clock());
}
