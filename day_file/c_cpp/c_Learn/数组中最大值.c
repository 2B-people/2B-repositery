#include<stdio.h>
#define MAXN 100

int maxinshuzhu(int *G);

int main(void) {
	int G[MAXN] = { 0 };
	for (int i = 0; G[i-1]!=-1; i++) {
		scanf("%d", &G[i]);
	}
	int result = maxinshuzhu(G);
	printf("½á¹ûÎª%d", result);
	return 0;
}

int maxinshuzhu(int *G) {
	for (int i = 0; G[i] != -1; i++) {
		for (int j = i + 1; G[j] != -1; j++) {
			if (G[j] > G[i]) {
				G[i] = 0;
			}
		}
		if (G[i] != 0) {
			return G[i];
			break;
		}
	}
}