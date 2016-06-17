#include <stdio.h>
#include <time.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <float.h>

int main()
{
	float x1, y1, x2 , y2;
	float R1, R2;
	float l;

	FILE * f = NULL;


    f=fopen("twoc.in","r");

	fscanf(f,"%f %f %f %f ",&x1, &y1, &x2, &y2);
	fscanf(f,"%f %f ",&R1, &R2);

	fclose(f);

	f=fopen("twoc.out", "w");

	l = (pow((x2 - x1),2) + pow((y2 - y1),2)); // distance between centers

	//fprintf(f, "%0.3lf ", l);
	//fprintf(f, "%0.3lf ", R1 + R2);

	if (l > pow((R1 + R2),2))
	{
		fprintf(f, "Too far") ;
	} ;

	if ((l < pow((R1 - R2),2)) && (R1 > R2) )
	{
		fprintf(f, "2 inside 1") ;
	} ;

	if ((l < pow((R1 - R2),2)) && (R1 < R2) )
	{
		fprintf(f, "1 inside 2") ;
	} ;


	//if(fabs(l-pow((R1 + R2),2) <= DBL_EPSILON * fmax(fabs(l),fabs(pow((R1 + R2),2)))))
	if (l == pow((R1 + R2),2))

	{
		fprintf(f, "Tangent: outside") ;
	} ;

	//if(fabs(l-pow((R1 - R2),2) <= DBL_EPSILON * fmax(fabs(l),fabs(pow((R1 - R2),2)))))

	if ((l == pow((R1 - R2),2)) && (R1 > R2))
	{
		fprintf(f, "Tangent: 2 in 1") ;
	} ;

	//if(fabs(l-pow((-R1 + R2),2) <= DBL_EPSILON * fmax(fabs(l),fabs(pow((-R1 + R2),2)))))

	if (l == pow((R2 - R1),2) && (R1 < R2))
	{
		fprintf(f, "Tangent: 1 in 2") ;
	}

	if ((l > pow((R1 - R2),2)) && (l < pow((R1 + R2),2)))
	{
		fprintf(f, "Intersect") ;
	} ;

	fclose(f);

	return 0;
}

