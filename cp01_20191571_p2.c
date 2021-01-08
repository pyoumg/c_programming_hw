#include <stdio.h>
#include <math.h>
void get_distance(double*, double*, double*, double*);

int main()
{
	double a, b, c, d;
	printf("Input a, b, c, d :");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	get_distance(&a, &b, &c, &d);
	printf("%.4lf\n", d);
	return 0;
}

void get_distance(double *pa, double *pb, double *pc, double *pd)
{
	*pd = (*pa - *pc)*(*pa - *pc) + (*pb - *pd)*(*pb - *pd);

	*pd = sqrt(*pd);
	return;
}