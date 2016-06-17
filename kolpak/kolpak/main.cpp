#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	float L, D, RK, M, r, H;

    FILE * f;


	f=fopen("pack.in","r");

	fscanf(f, "%f %f", &L, &D);

	fclose(f);
	r = D / 2;
    H = sqrt(pow(L,2)-pow(r,2));
    M = r / (sqrt(pow(H,2)+pow(r,2)));

    RK = (M * H ) / (1 + M);

	f=fopen("pack.out", "w");

	fprintf(f, "%0.4f", RK);

	fclose(f);

	return 0;
}
