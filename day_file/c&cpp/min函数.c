//����Сֵ����Ӧ��

#include<stdio.h>

double min(double x, double y) {
	if (x < y) {
		return x;
	}
	else if (x > y) {
		return y;
	}
	else {
		return 0.0;
	}
}

int main(void)
{
	double x=0.0;
	double y=0.0;
	printf("��������������");
	scanf("%lf %lf", &x, &y);
	double result = min(x, y);
	printf("result=%f", result);
	return 0;
}