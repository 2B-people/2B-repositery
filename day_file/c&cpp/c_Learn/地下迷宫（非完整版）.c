/*
题目描述
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;
1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)
(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),
小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,
向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。
现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
输入描述:
输入包括n+1行:
第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
接下来的n行:
每行m个0或者1,以空格分隔
输出描述:
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;
如果不能逃离迷宫,则输出"Can not escape!"。 测试数据保证答案唯一
示例1
输入
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
输出
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char map[11][11] = { '\0' };
int drl[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//方向
int P = -100,n,m;
bool jud = false;//判断用
void dfs(int xi,int yi);

int main()
{
	scanf("%d %d %d", &n, &m, &P);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	dfs( 1, 1);
	if (jud)
		printf("can do it");
	else
		printf("Can not escape");
	system("pause");
}

void dfs(int xi, int yi)
{
	if (jud)
		return;
	if (P <= 0)
		return;
	if (xi > n || yi > m || xi < 1 || yi < 1)
		return;
	if (P >= 0 && xi == n && yi == m-1)
	{
		jud = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (map[xi + drl[i][0]][yi + drl[i][1]] != 0)
		{
			if (i == 0 || i == 1)
			{
				P -= 1;
				dfs(xi + drl[i][0], yi + drl[i][1]);
				P += 1;
			}
			else if (i == 3)
			{
				P -= 3;
				dfs(xi + drl[i][0], yi + drl[i][1]);
				P += 3;
			}
			else
				dfs(xi + drl[i][0], yi + drl[i][1]);

		}
	}
}