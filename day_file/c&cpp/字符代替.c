/*�ַ��滻
�ú���replace���û�������ַ������ַ�t��T�����滻Ϊe��E��
�������滻�ַ��ĸ���*/

#include<stdio.h>
#include<string.h>
#define MAXN 100

int replace(char *a);

int main(void)
{
	char a[MAXN] = {NULL};
	printf("������һ���ַ���");
	gets(a);
	int number=replace(a);
	printf("�������ַ���Ϊ%s\n�滻�ַ��ĸ���Ϊ%d\n", a, number);
	return 0;
}

//int replace(char *a)/*ԭ����replace����*/ {
//	int number = 0;
//	for (int i = 0; i<MAXN; i++) {
//		if (a[i] == 't' ) {
//			a[i] = 'e';
//			number++;
//		}
//		else if (a[i] == 'T') {
//			a[i] = 'E';
//			number++;
//		}
//	}
//	return number;
//}

int replace(char *a)/*replace�Ż�����*/ {
	int number = 0;
	while (*a != '\0') {
		if (*a == 't') {
				*a = 'e';
				number++;
		}
			else if (*a == 'T') {
				*a = 'E';
				number++;
		}
			a++;
	}
	return number;
}
