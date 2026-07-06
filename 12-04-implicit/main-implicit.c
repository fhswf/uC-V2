
#include <stdio.h>
#include <stdint.h>

#define DEG2RAD 2/360*3.1415926535

int32_t hoch2(int32_t x)
{
    return x*x;
}


int main()
{
	uint32_t i=10;

	i=i*0.66;

	printf("i= %i\r\n", i);

	double d=10.0;
	d *= 1/2;
	printf("d= %f\r\n", d);

	printf("180.0 * DEG2RAD = %5.2f\r\n", 180.0*DEG2RAD); // Rechnung von 180.0 * 2 / 360 -> 180.0 * 2 -> 360.0 / 360 -> 1.0 * 3.1415926535 -> 3.1415926535
	printf("DEG2RAD * 180.0 = %5.2f\r\n", DEG2RAD*180.0); // Hier wird zuerst 2/360 berechnet, was 0 ist

	double y,q;
	y=5.6;
	q=hoch2(y);
	printf("y= %f, q= %f\r\n", y,q);

	d = (double)i;

	double e;
	d = 7.55;
	// Runden
	e = (int32_t)(d+0.5);


	return 0;

}


