/*
给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，
前后没有空格。 比如： （1） “hello xiao mi”->“mi xiao hello”
输入描述 :
	输入数据有多组，每组占一行，包含一个句子(句子长度小于1000个字符)
输出描述 :
	对于每个测试示例，要求输出句子中单词反转后形成的句子
	*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Reverse(char * str, int len);//逆序字符串
char* ReverseSentence(char* str);

int main()
{
	char str[1000] = { "\0" };
	gets_s(str, 1000);
	ReverseSentence(str);
	puts(str);
	system("pause");
	return 0;
}

char* Reverse(char* str,int len)
{
	if (str == NULL || len <= 0)
		return str;
	char* strhead = str;
	char* strlast = str + len - 1;
	for (; strlast > strhead/*判断依据*/; strhead++, strlast--)   //从头节点，位节点交换
	{
		char temp = *strlast;
		*strlast = *strhead;
		*strhead = temp;
	}
	return str;
}

char* ReverseSentence(char* str)
{
	if (str == NULL)
		return str;
	Reverse(str, strlen(str));   //整句逆转
	char *strhead = str;
	char *strlast = str;
	while (*strlast != '\0')     //每个单词逆序
	{
		for (; *strlast != '\0'&& *strlast != ' '; strlast++);
		Reverse(strhead, strlast - strhead);//指针的妙用，学习
		if (*strlast == '\0')
			break;
		strlast++;
		strhead = strlast;
	}
	return str;
}
