#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	float x1, y1, x2, y2;
	float A, B, C;


	FILE * f;


	f=fopen("line.in","r");

	fscanf(f,"%f %f %f %f",&x1, &y1, &x2, &y2);

	fclose(f);


	f=fopen("line.out", "w");
	A = y1 - y2;
	B = x2 - x1;
	C = x1 * y2 - x2 * y1;
	fprintf(f, "%0.3f %0.3f %0.3f", A, B, C);

	fclose(f);
}
