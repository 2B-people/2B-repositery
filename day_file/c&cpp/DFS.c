/*
dfs（深度搜索）
能否在 恰好T步时 从A点到达 D点，每个点只能走一次，X是障碍。
注意不能提前到达，必须在T步时到达
输入：n m t，地图的大小，t步
eg：
4 4 4
A...
..X.
.X..
...D
输出：
no
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

char map[9][9] = { '\0' };//地图
int drl[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//方向
int n, m, t;
int xd, yd/*门的坐标*/;
int num = 0;//记录障碍的个数
bool jud = false;//判断用

void dfs(int xi, int yi, int cot);

int main()
{
	int xi, yi;//开始的点
	scanf_s("%d %d %d", &n, &m, &t);
	getchar();      //把\n读掉
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = getchar();
			if (map[i][j] == 'A')
			{
				xi = i, yi = j;
				map[i][j] = 'X';
			}
			if (map[i][j] == 'D')
				xd = i, yd = j;
			if (map[i][j] == 'X')
				num++;
		}
		getchar();//把\n读掉
	}
	if (abs(xi - xd) + abs(yi - yd) > t)//超时剪枝
		printf("no");
	else if (t - (n*m - num) > 0)//可以走的路比时间少,不可能在规定时间达到，所以剪枝
		printf("no");
	else if ((t - abs(xi - xd) - abs(yi - yd)) % 2 != 0)//奇偶剪枝
		printf("no");
	else
	{
		dfs(xi, yi, 0);
		if (jud == true)
			printf("yes");
		else
			printf("no");
	}
	system("pause");
	return 0;
}

void dfs(int xi, int yi, int cot)
{
	if (jud)
		return;//找到之后就直接跳出
	if (xi == xd && yi == yd && cot == t)//成功条件
	{
		jud = true;
		return;
	}
	if (xi>n || yi>m || cot>t || xi<1 || yi<1)//越界剪枝
		return;
	if ((t - cot) - abs(xi - xd) - abs(yi - yd)<0)//超时剪枝
		return;
	for (int i = 0; i<4; i++)//四个方向搜索
		if (map[xi + drl[i][0]][yi + drl[i][1]] != 'X')
		{
			map[xi + drl[i][0]][yi + drl[i][1]] = 'X';
			dfs(xi + drl[i][0], yi + drl[i][1], cot+1);
			map[xi + drl[i][0]][yi + drl[i][1]] = '.';
		}
	return;
}

