/*һ������: 8 4 2 1 23 344 12
������Ϸ,�Ӽ�������������һ������,�ж��������Ƿ����������
*/

#include<stdio.h>

const int G[7] = { 8,4,2,1,23,344,12 };

int main()
{
	int num;
	while ((scanf("%d", &num)) != 1) {
		printf("��������ȷ��ʽ");
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