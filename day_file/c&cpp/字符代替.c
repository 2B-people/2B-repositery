/*字符替换
用函数replace将用户输入的字符串的字符t（T）都替换为e（E）
并返回替换字符的个数*/

#include<stdio.h>
#include<string.h>
#define MAXN 100

int replace(char *a);

int main(void)
{
	char a[MAXN] = {NULL};
	printf("请输入一个字符串");
	gets(a);
	int number=replace(a);
	printf("处理后的字符串为%s\n替换字符的个数为%d\n", a, number);
	return 0;
}

//int replace(char *a)/*原本的replace方案*/ {
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

int replace(char *a)/*replace优化方案*/ {
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
