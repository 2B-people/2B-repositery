#include<stdio.h>
#include<stdlib.h>

int n = 0;
float *Max_Min(float *p);

int main()
{
	float G[50];
	char i;
	float *p;
	scanf_s("%d", &n);
	for (i = 0; i<n; i++)
		scanf_s("%f", &G[i]);
	p = Max_Min(&G[0]);
	printf("%.2f\n%.2f\n", *p, *(p + 1));
	system("pause");
	return 0;
}

float *Max_Min(float *p)
{
	char i;
	float max_min[2] = { -1000000,1000000 };
	float *q = &max_min[0];
	for (i = 0; i<n; i++)
	{
		if (*(p + i)> max_min[0])
			max_min[0] = *(p + i);
		if (*(p + i) < max_min[1])
			max_min[1] = *(p + i);
	}
	return q;
}