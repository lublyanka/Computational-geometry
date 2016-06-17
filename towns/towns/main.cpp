#include <stdio.h>
#include <stdlib.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <limits>
#include <algorithm>
#include <string.h>

using namespace std;

struct Point
{
    signed int x, y;
};

Point *towns;
double *distMatrix;
int *startTownIndex;
int *finishTownIndex;

// calculate the distance between 2 town

double DistBetweenTown (const Point &p1, const Point &p2)
{
    return (double) sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
};

int main()
{
    int N, M;
    double maxdist=0;
    char sval[80];
    FILE * f;

//open file with input user data

    f=fopen("maxdist.in","r");

//read number of towns

	fscanf(f, "%d", &N);

//create towns

	towns = new Point [N];

// set coordinates of towns

	for(int i = 0; i < N; i++)
	{
		fscanf(f, "%d %d", &towns[i].x, &towns[i].y);
	}

//read number of towns

	fscanf(f, "%d", &M);

    startTownIndex = new int [M];
    finishTownIndex = new int [M];

//set roads between towns

	for(int i = 0; i < M; i++)
	{
		fscanf(f, "%d %d", &startTownIndex[i], &finishTownIndex[i]);
	}

//close file with input user data

	fclose(f);

//open file for output data

	fopen("maxdist.out", "w");

    double** distMatrix = new double*[N];
	for (int i=0; i < N; i++)
	{
	    distMatrix[i] = new double [N] ;
	}
//initialized matrix of distance between towns

	for (int i=0; i < N; i++)
    {
        for (int j=0; j < N; j++)
        {
            distMatrix [i][j] = std::numeric_limits<float>::max();
                    //fprintf(f,"%lf ", distMatrix[i][j]);
        }
    }

                    //fprintf(f,"\n");

//put "0" at the main line of matrix of distance between towns

    for (int i=0; i < N; i++)
    {
        distMatrix [i][i] = 0;
                    //fprintf(f,"%lf ", distMatrix[i][i]);

    }
                    //fprintf(f,"\n");
//put the real lenght to matrix of distance between towns
    for (int k = 0; k < M; k++)
    {
        distMatrix[startTownIndex[k]-1][finishTownIndex[k]-1] = DistBetweenTown (towns[startTownIndex[k]-1],towns[finishTownIndex[k]-1]);
                    //fprintf(f,"%lf", distMatrix[startTownIndex[k]-1][finishTownIndex[k]-1]);

    }
                    //fprintf(f,"\n");

// Floyd–Warshall algorithm http://e-maxx.ru/algo/floyd_warshall_algorithm

    for (int k=0; k < N; k++)
	{
        for (int i=0; i < N; i++)
        {
                for (int j=0; j < N; j++)
                {
                    distMatrix[i][j] = min(distMatrix[i][j],(distMatrix[i][k] + distMatrix[k][j]));
                    distMatrix[j][i] = distMatrix [i][j];
                    //fprintf(f,"%lf ", distMatrix[i][j]);
                }
        }
	}
                    //fprintf(f,"\n");

// select the max way

	for (int i=0; i < N; i++)
    {
        for (int j=0; j < N; j++)
        {
            if (distMatrix[i][j] == std::numeric_limits<float>::max())
            {
                distMatrix[i][j] = 0;
            }
            maxdist = max(maxdist,distMatrix[i][j]);
        }
    }
//write the answer in file
	if (M == 0)
	{
	    fprintf(f,"-1");
	}
	else
	{
	   sprintf(sval, "%.7f", maxdist);
       int lenh = strlen(sval);
       sval[lenh-1] = '\n';
       fprintf(f, "%s", sval);


	}
//close file for output data
	fclose(f);

                //delete []; don't forget to clean the memory
                //delete []; don't forget to clean the memory

	return 0;





}
