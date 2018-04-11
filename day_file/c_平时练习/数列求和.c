#pragma warning (disable : 4996)

#include<stdio.h>

int jiechen(int num);

int main()
{
	int num;
	double sum = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 1; i <= num; i++)
		sum += 1 / (double)jiechen(i);
	printf("%.2f", sum);
	getchar();
	return 0;
}

int jiechen(int num)
{
	int rel = 1;
	for (int i = 1; i < num; i++)
		rel *= i;
	return rel;
}