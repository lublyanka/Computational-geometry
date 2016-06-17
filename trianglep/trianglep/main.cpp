#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <cstdlib>
//#include <cstdio>
//#include <cmath>
#include <cassert>
#include <algorithm>
//#include <float.h>
using namespace std;

struct Pt
{
	float x;
	float y;
};

struct Triangle
{
	Pt K, L, M;
};

// Usable AlmostEqual function
bool AlmostEqual2sComplement(float A, float B, int maxUlps)
{
    // Make sure maxUlps is non-negative and small enough that the
    // default NAN won't compare as equal to anything.
    assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
    int aInt = *(int*)&A;
    // Make aInt lexicographically ordered as a twos-complement int
    if (aInt < 0)
        aInt = 0x80000000 - aInt;
    // Make bInt lexicographically ordered as a twos-complement int
    int bInt = *(int*)&B;
    if (bInt < 0)
        bInt = 0x80000000 - bInt;
    int intDiff = abs(aInt - bInt);
    if (intDiff <= maxUlps)
        return true;
    return false;
}

float square ( Pt K, Pt L, Pt M)
{
return (float) 0.5*fabs((K.x-L.x)*(M.y-L.y)-(K.y-L.y)*(M.x-L.x));
}

bool location (const Triangle &trianglic, const Pt &ObjectPoint) {
	float sABC = square(trianglic.K, trianglic.L, trianglic.M);
	float s1 = square(trianglic.K, trianglic.L, ObjectPoint);
	float s2 = square(trianglic.L, trianglic.M, ObjectPoint);
	float s3 = square(trianglic.M, trianglic.K, ObjectPoint);

	return AlmostEqual2sComplement(sABC, (s1 + s2 + s3), 4000);
}
int main()
{
    float  x1, y1, x2, y2, x3, y3, x, y, S;
    int N;
    Triangle trianglic;
    Pt ObjectPoint;

	FILE * f1, * f2;


	f1=fopen("trianglep.in","r");
	fscanf(f1,"%i", &N);
	f2=fopen("trianglep.out", "w");
    for (int i=0; i < N; i++)
    {
       	fscanf(f1,"%f %f %f %f %f %f",&trianglic.K.x, &trianglic.K.y, &trianglic.L.x, &trianglic.L.y, &trianglic.M.x, &trianglic.M.y);
        fscanf(f1, "%f %f", &ObjectPoint.x, &ObjectPoint.y);

        //S = square(x, y, x2, y2, x3, y3) + square(x1, y1, x, y, x3, y3) + square(x1, y1, x2, y2, x, y);
        //fprintf(f2,"%0.2f ", square(x1, y1, x2, y2, x3, y3));
        //fprintf(f2,"%0.2f ", square(x, y, x2, y2, x3, y3));
        //fprintf(f2,"%0.2f ", square(x1, y1, x, y, x3, y3));
        //fprintf(f2,"%0.2f ", square(x1, y1, x2, y2, x, y));

        //if (fabs(square(x1, y1, x2, y2, x3, y3) - S ) <= (DBL_EPSILON * fmax(fabs(square(x1, y1, x2, y2, x3, y3)),fabs(S))))
//        {
//            fprintf(f2,"YES\n");
//        }
//
//        else
//        {
//            fprintf(f2,"NO\n");
//        }

        if (location(trianglic, ObjectPoint))

        {
            fprintf(f2,"YES\n");
        }

        else
        {
            fprintf(f2,"NO\n");
        }



        //fprintf(f2,"%s\n", fubc(trianglic, ObjectPoint) ? "YES" : "NO");

    }

    fclose(f1);
    fclose(f2);
	return 0;
}
