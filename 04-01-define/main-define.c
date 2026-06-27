/*
 *  02-01-define  -  main-define.c
 *
 *  Beispiel zum Einsatz von #define
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Suedwestfalen - Studiengang Mechatronik
 *
 *  Created on: 24.02.2026
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>

#define PI 3.1415927
#define MIN(a,b) ((a)<(b)?(a):(b))


int main()
{
	   double u,r;
	   r = 3.0;
	   // ...
	   u = 2.0*PI*r;
	   printf("Umfang eines Kreises mit dem Radius r=%lf\n",r);
	   printf("U=%lf\n",u);
	   printf("PI = %lf\n",PI);
	   return 0;
}
