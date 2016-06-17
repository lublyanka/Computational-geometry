#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <float.h>
#include <limits>

typedef struct
{
    double x, y;
}   point;

point* points;

//double *coordX, * coordY ;

double DistanceP(const point& p1, const point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y-p2.y,2));
}

//double Distance (double index_coordinate_of_start, double index_coordinate_of_finish)
//{
//	return (double) sqrt( pow((coordX[index_coordinate_of_start]-coordX[index_coordinate_of_finish]),2) + pow((coordY[index_coordinate_of_start]-coordY[index_coordinate_of_finish]),2)   );
//}

int main()
{
	int N, Point1, Point2, Point3;
    	double Perimetr, minPerimetr;

	FILE * f;

//    minPerimetr = MAXDOUBLE;

    minPerimetr = std::numeric_limits<double>::max();

	f=fopen("triangles.in","r");

	fscanf(f, "%d", &N);

//	coordX= new double[N];
//	coordY= new double[N];

	points = new point[N];

	for(int i = 0; i < N; i++)
	{
//        fscanf(f, "%lf", &coordX[i]);
//        fscanf(f, "%lf", &coordY[i]);
        fscanf(f, "%lf", &points[i].x);
        fscanf(f, "%lf", &points[i].y);
	}

	fclose(f);


	f = fopen("triangles.out", "w");

	for (int i1=0; i1 < N; i1++)
	{
        for(int i2 = i1 + 1; i2< N; i2++)
        {
            for(int i3 = i2 + 1; i3< N; i3++)
            {
                if ((i1 != i2) &&  (i2 != i3) && (i1 != i3))
                {
//                    Perimetr = Distance(i1,i2) + Distance(i2,i3) + Distance(i1,i3);
                    Perimetr = DistanceP(points[i1], points[i2]) + DistanceP(points[i2], points[i3]) + DistanceP(points[i3], points[i1]);
                }

                if (Perimetr < minPerimetr)//(abs(Perimetr - minPerimetr) < DBL_EPSILON)
                {
                    minPerimetr = Perimetr;
                    Point1 = i1;
                    Point2 = i2;
                    Point3 = i3;
                }
            }
        }
    }

fprintf(f, "%d %d %d", Point1+1, Point2+1, Point3+1) ;

fclose(f);

delete[] points;

return 0;
}
