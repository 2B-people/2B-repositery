#include<stdio.h>

double tiaohepingjunshu(double x, double y) {
	x = 1 / x;
	y = 1 / y;
	double result = (x + y) / 2;
	result = 1 / result;
	return result;
}

int main(void)
{
	double x=0.0, y=0.0;
	scanf("%lf %lf", &x, &y);
	double result = tiaohepingjunshu(x, y);
	printf("%f", result);
	return 0;
}