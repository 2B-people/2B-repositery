#include<stdio.h>
#define CSIZE 4
typedef struct name
{
	char sname[20];
	char lname[20];
};

typedef struct student
{
	struct name names;
	double grade[3];
	double pgrade;
};

int main()
{
	struct student student[CSIZE];
	for (int i = 0; i < CSIZE; i++)
	{
		scanf_s("%s", &student[i].names.sname,10);
		scanf_s("%s", &student[i].names.lname,10);
		scanf_s("%lf", &student[i].grade[0]);
		scanf_s("%lf", &student[i].grade[1]);
		scanf_s("%lf", &student[i].grade[2]);
		student[i].pgrade = student[i].grade[0] + student[i].grade[1] + student[i].grade[2];
	}
	for (int i = 0; i < CSIZE; i++)
	{
		printf("%s", &student[i].names.sname, 10);
		printf("%s", &student[i].names.lname, 10);
		printf("%lf", &student[i].grade[0]);
		scanf_s("%lf", &student[i].grade[1]);
		scanf_s("%lf", &student[i].grade[2]);
	}
	return 0;
}