/*Problem Description
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。
Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j;
	int num;
	char G[50];
	scanf_s("%s", G, 50);
	for (i = 0; G[i] != '\0'; i++)           
		for (j = 0; G[j] != '\0'; j++)     //冒泡排序法找到最大值
			if (G[j]>=G[i])num = j;
	for (i = 0; G[i] != '\0'; i++) {
		if (G[i] == G[num] ) {             //与最大值相同的字符之后打印（max） 
			printf("%c", G[i]);
			printf("(max)");
		}
		else
		{
			printf("%c", G[i]);
		}
	}
	system("pause");
	return 0;
}