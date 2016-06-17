#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	float x, y, z;

	FILE * f;


	f=fopen("vector.in","r");

	fscanf(f,"%f %f %f",&x, &y, &z);

	fclose(f);


	f=fopen("vector.out", "w");

	fprintf(f,"%0.2f ", sqrt(x * x + y * y + z * z));

	fclose(f);

	return 0;
}
