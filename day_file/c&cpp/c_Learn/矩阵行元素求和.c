/*利用行指针计算每行元素之和*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m, sum = 0;
	int matrix[50][50];
	int (*p)[50] = &matrix[0];
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i<n; i++)                  //遍历读入
		for (int j = 0; j<m; j++)
			scanf_s("%d", &matrix[i][j]);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < m; j++)           //行指针代替元素累加
			sum += *(*(p + i) + j);
		printf("%d\n", sum);
		sum = 0;
	}
	system("pause");
	return 0;
}
	