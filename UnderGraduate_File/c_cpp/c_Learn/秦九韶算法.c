#include<stdio.h>
#include<stdlib.h>
void main()
{
	static int a[10];
	static int i;
	int j, o, x, ans;
	char c;
	printf("���뷽��ϵ��\n");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
		c = getchar();/*�ж�����һ��ϵ���������ǿո��ǻس�*/
		if (c == '\n')
			break;/*�������س��������������*/
	}
	o = i + 1;/*��¼����ϵ���ĸ���*/
	printf("f(x)=");
	for (j = 0; j<10; j++, i--)
	{
		printf("(%d)x^(%d)", a[j], i);
		if (i>0)
			printf("+");
		if (i <= 0)
			break;
	}/*����������ʾ��Ҫ���ķ���*/
	printf("\n����x=?");
	scanf("%d", &x);
	printf("x=%d\n", x);/*���벢��ʾxȡֵ*/
	ans = a[0];
	for (j = 1; j<o; j++)
	{
		ans = ans * 4 + a[j];
	}/*�㷨�ļ�����*/
	printf("the answer is %d\n", ans);/*������*/
	system("pause");
}
