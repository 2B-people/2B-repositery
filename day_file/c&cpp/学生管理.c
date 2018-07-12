#include <stdio.h>
#include <stdlib.h>

//宏，代替所有5
#define N 5   //人数
#define M 3   //课程

//学生数据结构体
struct stu
{
    char name[15];      //名字
    char num[6];        //学号
    float score[M];     //成绩
    float aver;         //平均值
} student[N]/*定义了全局的结构体变量*/;

//函数声明
void sort(struct stu student[]);//排序学生
void writetofile(struct stu student[], char filename[], char mode[]);//数据写入文件

//main
int main(int argc, char const *argv[])
{
    FILE *fp;
    struct stu *ptr = NULL;

    //输入
    printf("input data:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", student[i].name, student[i].num);
        student[i].aver = 0;
        for (int j = 0; j < M; j++)
        {
            scanf("%f", &student[i].score[j]);
            student[i].aver += student[i].score[j];
        }
    }

    //写入文件
    writetofile(student, "student.txt", "w");
    writetofile(student, "sort.txt", "w");
    writetofile(student, "sort2.txt", "w");

    //排序后加在sort后
    sort(student);
    writetofile(student, "sort.txt", "a");

    //追加一名成员
    ptr = (struct stu *)malloc(sizeof(struct stu));
    scanf("%s %s",ptr->name,ptr->num);
    ptr->aver = 0;
    for(int i = 0;i<M;i++)
    {
        scanf("%f",&ptr->score[i]);
        ptr->aver += ptr->score[i];
    }

    if((fp = fopen("sort2.txt","a"))==NULL)
    {
        printf("cannot open file");
        exit(-1);
    }
    fprintf(fp,"%s %s",ptr->name,ptr->num);
    for(int j = 0;j<M;j++)
    {
        fprintf(fp,"%7.2f\n",ptr->score[j]);
    }
    fprintf(fp,"%7.2f\n",ptr->aver/M);
    fclose(fp);

    return 0;
}

//函数定义
void sort(struct stu student[])
{
    struct stu temp;
    for(int i = 0, k = i;i<N-1;i++)
    {
        k = i;
        for(int j = i+1;j<N;j++)//排序
        {
            if(student[j].aver <student[k].aver)
                k = j;
        }
        if(k != i)
        {
            temp = student[i];
            student[i] = student[k];
            student[k] = temp;
        }
    }
}

void writetofile(struct stu student[], char filename[], char mode[])
{
    FILE *fp;
    //打开文件
    if((fp = fopen("sort2.txt","a"))==NULL)
    {
        printf("cannot open file");
        exit(-1);
    }
    
    for(int i = 0; i < N; i++)
    {
        fprintf(fp,"%s %s",student[i].name,student[i].num);
        
        for(int j = 0; j < M; j++)
        {
            fprintf(fp,"%7.2f",student[i].score[j]);
        }
        fprintf(fp,"%7.2f\n",student[i].aver/M);        
    } 
    fclose(fp);   
}
