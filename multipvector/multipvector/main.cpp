#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define USE_MATH_DEFINES
#include <math.h>

int main()
{
	int N;
    double *vecA, *vecB;
    double multvecAB;
	FILE * f;


	f=fopen("product.in","r"); //open file with input user data

	fscanf(f, "%d", &N); //read input user data

	vecA = new double [N]; //create first vector A
	vecB = new double [N]; //create second vector B

	for(int i = 0; i < N; i++)
	{
		fscanf(f, "%lf", &vecA[i]); // set coordinates for first vector A
	}

	for(int i = 0; i < N; i++)
	{
		fscanf(f, "%lf", &vecB[i]); // set coordinates for second vector B
	}

	fclose(f); //close file with input user data



	fopen("product.out", "w"); //open file for output data


    multvecAB = NULL;

	for (int i=0; i < N; i++)
	{
				multvecAB = multvecAB + vecA[i]*vecB[i]; //Scalar multiplication of vector A & vector B
				    // fprintf(f, "%0.3lf",multvecAB);
	}
    fprintf(f, "%0.3lf",multvecAB); //write the answer in file

	fclose(f); //close file for output data

    //delete vecA[];
    //delete vecB[];

	return 0;
}
