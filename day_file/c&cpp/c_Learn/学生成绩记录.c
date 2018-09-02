/*建立一个链表，包含学生姓名和一门成绩并输出。*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct student 
{
    char name[10];
    int score;
    struct student *pNext;
}student,*Pstudent;

Pstudent create(void)  //创建链表
{
    int len;
    Pstudent pHead=(Pstudent)malloc(sizeof(student));
    if(pHead==NULL)
    {
        printf("error!\n");
        exit(-1);
    }
    else
    {
        Pstudent pTail=pHead;
        pHead->pNext=NULL;
        printf("Please input the len:");
        scanf_s("%d",&len);
        for(int i=0;i<len;i++)
        {
            Pstudent p=(Pstudent)malloc(sizeof(student));
            if(p==NULL)
            {
                printf("error!\n");
                exit(-1);
            }
            else
            {
                printf("Please input student's name and score:");
                scanf_s("%s",pTail->name,10);
                scanf_s("%d",&pTail->score);
                pTail->pNext=p;
                p->pNext=NULL;
                pTail=p;
            }
        }
    }
    return pHead;
}


bool print(Pstudent pHead)//输出链表
{
    Pstudent p=pHead;
    while(p!=NULL)
    {
        printf("name:%s score:%d\n",p->name,p->score);
        p=p->pNext;
    }
}

int main()
{
    Pstudent pHead=Create();
    if(print(pHead)!=true)printf("print error!\n");
    system("pause");
    return 0;
}