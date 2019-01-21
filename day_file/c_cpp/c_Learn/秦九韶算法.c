#include<stdio.h>
#include<stdlib.h>
void main()
{
	static int a[10];
	static int i;
	int j, o, x, ans;
	char c;
	printf("输入方程系数\n");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
		c = getchar();/*判断输入一个系数结束后是空格还是回车*/
		if (c == '\n')
			break;/*如果输入回车，代表输入结束*/
	}
	o = i + 1;/*记录输入系数的个数*/
	printf("f(x)=");
	for (j = 0; j<10; j++, i--)
	{
		printf("(%d)x^(%d)", a[j], i);
		if (i>0)
			printf("+");
		if (i <= 0)
			break;
	}/*以上用来显示需要求解的方程*/
	printf("\n输入x=?");
	scanf("%d", &x);
	printf("x=%d\n", x);/*输入并显示x取值*/
	ans = a[0];
	for (j = 1; j<o; j++)
	{
		ans = ans * 4 + a[j];
	}/*算法的简单描述*/
	printf("the answer is %d\n", ans);/*输出结果*/
	system("pause");
}
