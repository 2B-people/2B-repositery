#pragma warning(disable:4996);
#include <stdio.h>


int main()
{
	int data[6][6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == j)
				data[i][j] = 1;
			if (i == j + 1)
				data[i][j] = 2;
			if (i == j + 2)
				data[i][j] = 3;
			if (i == j + 3)
				data[i][j] = 4;
			if (i == j + 4)
				data[i][j] = 5;
			if (i == j + 5)
				data[i][j] = 6;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}