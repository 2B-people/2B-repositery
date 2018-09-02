/*编写一个函数（参数用指针）将一个 N×N 矩阵顺时针输出，先输入 N。
输入样例：3 3 1 2 3 4 5 6 7 8 9
输出样例：1 2 3 6 9 8 7 4 5*/

#include <stdio.h>

#define MAXSIZE 100

int arr[MAXSIZE][MAXSIZE] = { 0 };//全局二维数组，存储矩阵
int threshold_m = 0;
int threshold_n = 0;
void printMatrix(int m, int n);

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)//读入矩阵
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	threshold_n = n;
	threshold_m = m;
	for (int i = 0, j = 0; i < threshold_m && j < threshold_n; i++, j++) //指向下一圈的第一个元素；
	{
		printMatrix(i, j);
		threshold_n--;
		threshold_m--;
	}
	printf("\n");
	return 0;
}

void printMatrix(int m, int n)//打印最外围一圈；
{
	int i = m, j = n;
	for (; j<=threshold_n; j++)//输出首行
	{
		printf("%d ", arr[i][j]);
	}
	j--;
	for (i++; i<threshold_m; i++) //输出末列
	{
		printf("%d ", arr[i][j]);
	}
	i--;
	for (j--; j >= n && i != m; j--)//输出末行
	{
		printf("%d ", arr[i][j]);
	}
	j++;
	for (i--; i>m && j != threshold_n - 1; i--)//输出首列
	{
		printf("%d ", arr[i][j]);
	}
}
