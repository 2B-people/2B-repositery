//�ж�������ַ����Ƿ�Ϊ�����ġ���˳���͵�����һ�����ַ���
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXN 100

int judgehuiwen(char *str1, char *str2);//�ж������ַ����Ƿ�Ϊ�����ġ�

int main(void)
{
	char str1[100], str2[100];
	printf("Enter a stringG,please.\n");
	gets(str1);
	printf("Enter a stringH,please\n");
	gets(str2);
	int judgenum=judgehuiwen(str1, str2);
	if (judgenum == 1) {
		printf("�������ַ���Ϊ����\n");
	}
	else {
		printf("�������ַ������ǻ���\n");
	}
	system("pause");
	return 0;
}

int judgehuiwen(char *str1, char *str2)
{
	if ((sizeof(str1) / sizeof(str1[0])) != (sizeof(str2) / sizeof(str2[0]))) {
		return 0;
	}
	else {
		int judge = 0;
		int i = 0;
		int j = (sizeof(str2) / sizeof(str2[0])) - 2;
		for (; i < (sizeof(str1) / sizeof(str1[0])) - 1; i++, j--) {
			if (str1[i] == str2[j])
				judge++;
		}
		if (judge == ((sizeof(str1) / sizeof(str1[0]))-1))
			judge = 1;
		return judge;
	}
}

int main()
{
	printf("fmfmfmfm")

	for(int i=0;i<len;i++)
	{
		ifor
	}
}