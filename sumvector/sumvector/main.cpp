#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define USE_MATH_DEFINES
#include <math.h>

int main()
{
	int N;
    float *sumvA, *sumvB;

	FILE * f;


	f=fopen("sum.in","r");

	fscanf(f, "%d", &N);

	sumvA = new float[N];
	sumvB = new float[N];

	for(int i = 0; i < N; i++)
	{
		fscanf(f, "%f", &sumvA[i]);
	}

	for(int i = 0; i < N; i++)
	{
		fscanf(f, "%f", &sumvB[i]);
	}

	fclose(f);


	fopen("sum.out", "w");

	for (int i=0; i < N; i++)
	{
		fprintf(f, "%0.3f ", sumvA[i] + sumvB[i]);
	}
	fclose(f);


	return 0;
}
