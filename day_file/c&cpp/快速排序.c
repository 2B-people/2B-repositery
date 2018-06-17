/*7. 设某组有 N 个人，填写如下的登记表，除姓名、学号外，还有三科成绩，
编程实现对表格的计算，求解出每个人的三科平均成绩，求出四个学生的单科平均，
并按平均成绩由 高分到低分输出。要求排序使用快速排序*/

#include<stdio.h>
#include<stdlib.h>
#include<Stdbool.h>

typedef struct student
{
    char name[50];
    int studynumber;
    int class1,class2,class3;
    int class;
    int pNext;
}student,*Pstudent;

struct student stu[100];
int len;

void quicksort(int left,int right);

int main()
{
    scanf_s("%d",&len);
    for(int i=0;i<len;i++)
    {
        printf("Please input the samething\n");
        scanf_s("%s",stu[i].name,20);
        scanf_s("%d",&stu[i].studynumber);
        scanf_s("%d %d %d",&stu[i].class1,&stu[i].class2,&stu[i].class3);
        stu[i].class=stu[i].class1+stu[i].class2+stu[i].class3;
    }
    quicksort(1,len);
}

void quicksort(int left,int right)
{
    int i,j,temp;
    if(left>right)
        return;
    temp=stu[left].class;
    i=left;
    j=right;
    while(i!=j)
    {
        while(stu[j].class>=temp && i<j)
            j--;
        while(stu[i].class<=temp && i<j)
            i++;
        if(i<j)
        {
            temp=stu[i].class;
            stu[i].class=stu[j].class;
            stu[j].class=temp;
        }
    }
    stu[left].class=stu[i].class;
    stu[i].class=temp;
    quicksort(left,i-1);
    quicksort(i+1,right);
}


