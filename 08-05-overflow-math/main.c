/************************************
 *
 * File Name:  main.c
 * Path:       /08-05-overflow-math/main.c
 * Created on: 27.05.2026
 * Author:     tobi
 *
 ************************************/

#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t old = 65430;
	uint16_t act = 65527;

	uint16_t diff;

	diff = act - old;
	printf("(1) act: %6d  old: %6d  diff: %6d\n", act, old, diff);

	//Next step
	old = act;
	act = 87;

	diff = act - old;
	printf("(2) act: %6d  old: %6d  diff: %6d\n", act, old, diff);

	return 0;
}

