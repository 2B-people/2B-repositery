/*一个数列: 8 4 2 1 23 344 12
猜数游戏,从键盘中任意输入一个数据,判断数列中是否包含此数据
*/

#include<stdio.h>

const int G[7] = { 8,4,2,1,23,344,12 };

int main()
{
	int num;
	while ((scanf("%d", &num)) != 1) {
		printf("请输入正确格式");
		scanf("%s*");
	}
	int judge = 0;
	for (int i = 0; i < (sizeof(G) / sizeof(G[0])); i++) {
		if (num == G[i]) {
			printf("ok,you are wining\n");
			judge = 1;
			break;
		}
	}
	if (judge != 1) {
		printf("sorry,you are failed");
	}
	return 0;
}