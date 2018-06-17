/*题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如 : n = 3时，3个整数13, 312, 343, 连成的最大整数为34331213。
	如 : n = 4时, 4个整数7, 13, 4, 246连接成的最大整数为7424613。
	输入描述 :
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N <= 100），
第二行包含N个数(每个数不超过1000，空格分开)。
输出描述 :
每组数据输出一个表示最大的整数。

失败：无法识别十位是0的百数，
原因：整数类型，傻逼算法
*/

#include<stdio.h>
#include<stdlib.h>

int quwei(int n)
{
	int x=0;
	if (n / 100)
		x = n/100;
	else if (n / 10)
		x = n/10;
	else if (n / 1!=0)
		x = n;
	return x;
}

int main()
{
	int num;
	int G[100];
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &G[i]);
	for(int i=0;i<num;i++)
		for (int j = i + 1; j < num; j++)
		{
			int swep;
			if (quwei(G[i]) < quwei(G[j]))//最高位比较
			{
				swep = G[i];
				G[i] = G[j];
				G[j] = swep;
			}
			else if (quwei(G[i]) == quwei(G[j]) && ((G[i] > 10 && G[j] < 10) || (G[i] < 10 && G[j]>10)))//首位相同优先个位
			{
				if (G[i] < 10 && G[j] < 10)
				{
					swep = G[i];
					G[i] = G[j];
					G[j] = swep;
				}
			}
			else if (quwei(G[i]) == quwei(G[j]) && ((G[i] > 10 && G[j] > 100 && G[i] < 100) || (G[i] > 100 && G[j] > 10 && G[j] < 100)))//百数和十位交换
			{
				if (G[i] < 100 && G[j]>100)//G[i]为十位G[j]为百位
				{
					if (quwei(G[i] % 10) < quwei(G[j] % 100))
					{
						swep = G[i];
						G[i] = G[j];
						G[j] = swep;
					}
					else if (quwei(G[i] % 10) == quwei(G[j] % 100)&&quwei(G[i])<quwei(G[i]%10))
					{
						swep = G[i];
						G[i] = G[j];
						G[j] = swep;
					}
				}
				else//G[i]为百位G[j]为十位
				{
					if (quwei(G[i] % 100) < quwei(G[j] % 10))
					{
						swep = G[i];
						G[i] = G[j];
						G[j] = swep;
					}
				}
			}
			else if (quwei(G[i]) == quwei(G[j]) && G[i] > 10 && G[j] > 10 && G[i] < 100 && G[j]>10)//两个数都是十位交换
			{
				if (quwei(G[i] % 10) < quwei(G[j] % 10))
				{
					swep = G[i];
					G[i] = G[j];
					G[j] = swep;
				}
			}
			else if (quwei(G[i]) == quwei(G[j]) && G[i] > 100 && G[j] > 100)//两个数都是百位交换
			{
				if (quwei(G[i] % 100) < quwei(G[j] % 100) && G[i] - quwei(G[i] * 100) > 10 && (G[i] - quwei(G[i] * 100) > 10))
				{
					swep = G[i];
					G[i] = G[j];
					G[j] = swep;
				}
				else if (quwei(G[i] % 100) < quwei(G[j] % 100) && G[i] - quwei(G[i] * 100) < 10)
				{
					swep = G[i];
					G[i] = G[j];
					G[j] = swep;
				}
				else if (quwei(G[i] % 100) == quwei(G[j] % 100))
					if (quwei(G[i] % 10) < quwei(G[j] % 10))
					{
						swep = G[i];
						G[i] = G[j];
						G[j] = swep;
					}
			}
		}
	for (int i = 0; i < num; i++)
		printf("%d", G[i]);
	system("pause");
	return 0;


/*字符串A+B>B+A，就认为A>B*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int num;
	char data[100][5] = { '\0' };
	char temp[5] = { '\0' };
	char tempa[7] = { '\0' }, tempb = { '\0' };
	scanf_s("%d", &num);
	for (int i = 0; i<num; i++)
		scanf_s("%s", data[i],5);
	strcpy_s(temp,5, data[0]);
	for (int i = 0; i<num; i++)
	{
		for (int j = i + 1; j<num; j++)
		{
			strcpy_s(tempa,5, data[i]);     //其实这就是个字符串的冒泡排序，如果字符串A+B>B+A那么认为A>B
			strcat_s(tempa,5, data[j]);
			strcpy_s(tempb,5, data[j]);
			strcat_s(tempb,5, data[i]);
			if (strcmp(tempa, tempb)<0)
			{
				strcpy_s(temp,5, data[i]);
				strcpy_s(data[i],5, data[j]);
				strcpy_s(data[j],5, temp);
			}
		}
		printf("%s", data[i]);
	}
	system("pause");
	return 0;
}