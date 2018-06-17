/*
Problem Description
期中考试过去之后老师们因为统计分数的事情忙的天昏地暗，
在老师将两个班的成绩分别从低到高统计好之后因为教学评测的事情老师没有多余的时间来将两个班的成绩合并在一起了，
于是老师找到了作为课代表的你，希望你能完成这个任务。
给出两个班的成绩（已经从小到大排列好），将所有人的成绩从小到大排列好。 
Input
输入第一行为一个整数T，代表数据组数。每组数据第一行为两个整数n，m，
（1<=n,m<=1000）表示a，b两个序列的长度，第二行为a序列的所有元素，第三行为b序列的所有元素。
数据保证a，b序列元素从小到大依次给出，元素的大小不会超过100且为正整数。 
Output
对于每组数据输出共一行，表示排序后的序列，每个数后跟一个空格
*/

#include<stdio.h>

int main()
{
	int n, m, T,a,i;
	int G[50][1000], H[50][1000];
	scanf("%d", &T);
	for (a = 0; a<T; a++)
	{
		scanf("%d %d", &n , &m);
		for (i = 0; i<n; i++)
			scanf("%d", &G[a][i]);
		for (i = 0; i<m; i++)
			scanf("%d", &H[a][i]);
	}
	int j = 0, k = 0;
	for(a=0;a<T;a++)
	{
		for (i = 0; i<n + m; i++)
		{
			if (k == m)
				printf(" %d", G[a][j++]);
			else if (j == n)
				printf(" %d", H[a][k++]);
			else if (G[a][j] == H[a][k])
			{
				if (j==0||k==0)
				{
					printf("%d", G[a][j++]);
					printf(" %d", H[a][k++]);
				}
				else
				{
					printf(" %d", G[a][j++]);
					printf(" %d", H[a][k++]);
				}
				i++;
			}
			else if (G[a][j] > H[a][k])
			{
				if (j == 0 || k == 0)
					printf("%d", H[a][k++]);
				else
					printf(" %d", H[a][k++]);
			}
			else if (G[a][j] < H[a][k])
			{
				if (j == 0 || k == 0)
					printf("%d", G[a][j++]);
				else
					printf(" %d", G[a][j++]);
			}
			printf("\n");	
		}
	}
		return 0;
}