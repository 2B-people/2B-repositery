/*
Problem Description
Bogo排序（bogo-sort）是个既不实用又原始的排序算法。
其方法等同于把待排序的元素写在纸片上，随机变换纸片顺序，然后检查是否有序。如果无序那就再来一次。
现在给定一组数字，它的Bogo排序结果可能有多少种？试着写程序计算一下。数字从小到大依次给出
注意：纸片上的字符可能会有重复，但你的程序不应该把重复序列计算在内。
Input
输入包含多组，每组共两行，第一行N为纸片的数量。第二行为N个空格分隔的数字，表示每张纸片上写着的数字。
Output
对于每组输入输出一行，即可能排序结果的个数
*/

#include<stdio.h>

int jiecheng(int n)
{
	int i;
	int sum=1;
	for (i = 1; i <= n; i++)
		sum *= i;
	return sum;
}

int main()
{
	int N,i,j,num=0,sum=1;
	int G[1000];
	scanf_s("%d", &N);
	for (i = 0; i < N; i++)
		scanf_s("%d", &G[i]);
	for (i = 0; i < N; i=j+1)
	{
		for (j = i + 1; j < N; j++)
		{
			if (G[j] != G[i])
				break;
			if (G[j] == G[i])
				num++;
			if (G[j + 1] != G[i])
				break;
		}
		if (num != 0)
			sum *= jiecheng(num+1);
		num = 0;
	}
	printf("%d", jiecheng(N) / sum);
	return 0;
}