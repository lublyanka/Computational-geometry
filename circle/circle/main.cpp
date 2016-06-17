#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	float R, diametr, length_circle, square_circle;

    FILE * f;


	f=fopen("radius.in","r");

	fscanf(f, "%f", &R);

	fclose(f);


	diametr = 2 * R;
	length_circle = 2 * M_PI * R;
	square_circle = M_PI * R * R;


	f=fopen("radius.out", "w");

	fprintf(f, "%0.3f %0.3f %0.3f", diametr, length_circle, square_circle);

	fclose(f);

	return 0;
}
