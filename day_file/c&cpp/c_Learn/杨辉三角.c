#include<stdio.h>
#include<stdlib.h>

int c(int x, int y);

int main()
{
	int i, j, n = 13;
	printf("N=");
	while (n > 12)scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 24 - 2 * i; j++) {
			printf(" ");
		}
		for (j = 0; j < i + 1; j++) {
			printf("%4d", c(i,j));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

int c(int x, int y) {
	int z;
	if ((y == 0) || (y == x)) {
		return 1;
	}
	else {
		z = c(x - 1, y - 1) + c(x - 1, y);
		return z;
	}
}