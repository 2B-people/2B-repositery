#pragma warning(disable:4996);
#include <stdio.h>
 
int main()
{
	int n = 0;
	int data[100][100] = { 0 };
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i <= j)
				data[i][j] = i+1;
			if (i >= j)
				data[i][j] = j+1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}