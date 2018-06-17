#pragma warning (disable : 4996)
/*
A班学生成绩管理问题之姓名与成绩。
①更改原数组结构，增添“姓名”一项，输入A班的学生姓名
（②重新实现前6个功能
③在菜单中增加一项“6)Sort by name and print”。）
编写函数实现按字典顺序将姓名排序并输出。

输入描述
输入4个人的名字和3门功课成绩

输出描述
按字典顺序将姓名排序并输出每个人的成绩及均分（保留1位小数）
*/

#include<stdio.h>
#include<string.h>

#define CSIZE 4

struct Name
{
	char fname[10];
	char lname[10];
};
struct Student
{
	struct Name name;
	double grade[3];
	double pgrade;
};

struct Student student[CSIZE];

void sort(void);
int main()
{
	int i;

	for (i = 0; i < CSIZE; i++)
	{
		scanf("%s %s", &student[i].name.fname, &student[i].name.lname);
		scanf("%lf %lf %lf", &student[i].grade[0], &student[i].grade[1], &student[i].grade[2]);
		student[i].pgrade = (student[i].grade[0] + student[i].grade[1] + student[i].grade[2]) / 3;
	}

	sort();

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

void sort(void)
{
	int i, j,k;
    struct Student swap;
	for (i = 0; i < CSIZE; i++)
		for(j = 0;j < CSIZE; j++)
			if (strcmp(student[i].name.fname,student[j].name.fname)>0)
			{
				strcpy(swap.name.fname,student[j].name.fname);
				strcpy(swap.name.lname,student[j].name.lname);
				strcpy(student[j].name.fname,student[i].name.fname);
				strcpy(student[j].name.lname,student[i].name.lname);
                strcpy(student[i].name.fname,swap.name.fname);
				strcpy(student[i].name.lname,swap.name.lname);
				for(k=0;k<3;k++)
				{
					swap.grade[k]=student[j].grade[k];
					student[j].grade[k]=student[i].grade[k];
					student[i].grade[k]=swap.grade[k];
				}
				swap.pgrade=student[j].pgrade;
				student[j].pgrade=student[i].pgrade;
				student[i].pgrade=swap.pgrade;
			}
}