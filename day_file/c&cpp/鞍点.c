#include<stdio.h>
#define MAXN 105
#define INF 1e9

int G[MAXN][MAXN];
int maxInRov[MAXN], minInCol[MAXN];

int judge(int N,int *x,int*y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G[i][j] == minInCol[j] && G[i][j] == maxInRov[i]) {
				*x = i; *y = j;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < MAXN; i++) {
		minInCol[i] = (INF);
	}
	for (int i = 0; i < MAXN; i++) {
		maxInRov[i] = -(INF);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &G[i][j]);
			if (G[i][j] > maxInRov[i]) {
				maxInRov[i] = G[i][j];
			}
			if (G[i][j] < minInCol[j]) {
				minInCol[j] = G[i][j];
			}
		}
	}
	int x = -1, y = -1;
	if (judge(N, &x, &y)) {
		printf("%d %d", x , y );
	}
	else {
		printf("NO");
	}
	return 0;
}