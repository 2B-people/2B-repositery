#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[10][100];
	int num;
	scanf_s("%d", &num);
	getchar();
	fflush(stdin);
	for (int i = 0; i<num; i++)
		gets_s(str[i], 100);
	for (int i = 0; i < num-1; i++)
		for (int j = i + 1; j<num; j++)
		{
			if (strcmp(str[j], str[i])<0)
			{
				char temp[10];
				strcpy_s(temp,10, str[j]);
				strcpy_s(str[j],10,str[i]);
				strcpy_s(str[i],10, temp);
			}
		}
	for (int i = 0; i<num; i++)
		puts(str[i]);
	system("pause");
	return 0;
}