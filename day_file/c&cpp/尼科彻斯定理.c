#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MIN 1

int main()
{
	int m;
	int judge;
	printf("input : ");
	while ((judge = scanf_s("%d", &m)) != 1 || (m < MIN || m>MAX)) {
		if (judge != 1) {
			scanf_s("%*s");
		}
		printf("Enter an integer from 1 to 100,please.\n");
	}
	printf("output:%d^3=%d", m, m*m*m);
	int num = m*m - m + 1;
	printf("=%d", num);
	for (int i = 1; i < m; i++) {
		num = num + 2;
		printf("+%d", num);
	}
	printf("\n");
	system("pause");
	return 0;
}