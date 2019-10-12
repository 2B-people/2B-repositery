/*
题目描述
写一个程序，满足下列要求：
a)外部定义一个name结构体，它含有2个成员：
一个字符串用于存放名字，另一个字符串用于存放姓氏。
b)外部定义一个student结构体，它含有3个成员：
一个name结构体，一个存放3个浮点数分数的grade数组，
以及一个存放这3个分数的平均分的变量。
c)使用main()函数声明一个具有CSIZE（CSIZE = 4）个student结构的数组，
并随意初始化这些结构的名字部分。使用函数来执行d、e、f以及g部分所描述的任务。
d)请求用户输入学生姓名和分数，以获取每个学生的成绩。
将分数放到相应结构的grade数组成员中。
可以自主选择在main()或一个函数中实现这个循环。
e)为每个学生计算平均分，并把这个值赋给适合的成员。
f)输出每个结构体中的信息。
g)输出结构体的每个数值成员的班级平均分。

输入描述
请求用户输入学生姓名和分数。

输出描述
输出student结构体的全部信息。
*/
#include<stdio.h>
#define CSIZE 4

struct Name
{
	char fname[10];
	char lname[10];
};
struct Student
{
	struct Name name;
	double grade[3] ;
	double pgrade;
};

int main()
{
	//freopen("input.txt", "r", stdin);
	struct Student student[CSIZE];
	int i;
	for (i = 0; i < CSIZE; i++)
	{
		scanf("%s %s", &student[i].name.fname, &student[i].name.lname);
		scanf("%lf %lf %lf", &student[i].grade[0], &student[i].grade[1], &student[i].grade[2]);
		student[i].pgrade = (student[i].grade[0] + student[i].grade[1] + student[i].grade[2]) / 3;
	}
	for (i = 0; i < CSIZE; i++)
	{
		printf("%s %s ", student[i].name.fname, student[i].name.lname);
		printf("%.1f %.1f %.1f ", student[i].grade[0], student[i].grade[1], student[i].grade[2]);
		printf("%.1f", student[i].pgrade);
		printf("\n");
	}
	getchar();
	return 0;
}