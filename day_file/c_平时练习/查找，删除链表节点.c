#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct student
{
	char name[10];
	int score;
	struct student *pNext;
}student, *Pstudent;

Pstudent create(void)//创造一个链表
{
	int len;
	Pstudent pHead = (Pstudent)malloc(sizeof(student));
	if (pHead == NULL)
	{
		printf("error!\n");
		exit(-1);
	}
	else
	{
		Pstudent pTail = pHead;
		pHead->pNext = NULL;
		printf("Please input the len:");
		scanf_s("%d", &len);
		for (int i = 0; i<len; i++)
		{
			Pstudent p = (Pstudent)malloc(sizeof(student));
			if (p == NULL)
			{
				printf("error!\n");
				exit(-1);
			}
			else
			{
				printf("Please input student's name and score:");
				scanf_s("%s", pTail->name, 10);
				scanf_s("%d", &pTail->score);
				pTail->pNext = p;
				p->pNext = NULL;
				pTail = p;
			}
		}
	}
	return pHead;
}


Pstudent search(Pstudent pHead, char name[10])//查找节点
{
	Pstudent p = pHead;
	while (p->pNext != NULL)
	{
		
		if (stricmp(p->name, name))
		{
			p = p->pNext;
		}
		else
		{
			return p;
		}
	}
	printf("error,can't found and return pHead!\n");
	return pHead;
}

bool print(Pstudent pHead)//输出链表
{
	Pstudent p = pHead;
	while (p->pNext != NULL)
	{
		int jud = printf("name:%s grade:%d.\n", p->name, p->score);
		if (jud != 0)
		{
			p = p->pNext;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Delete(Pstudent pHead, int pos)//删除一个节点
{
	int i;
    Pstudent p = pHead;
	for ( i = 0; i<pos - 1&&p!=NULL; i++)
	{
		p = p->pNext;
	}
    if(i<pos-1||p==NULL)
        return false;
	Pstudent q = p->pNext;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
	return true;
}


int main()
{
	Pstudent pHead = create();
	char name[10];
	scanf_s("%s", name, 10);
	Pstudent p = search(pHead, name);
	printf("%s %d\n", p->name, p->score);
	if (Delete(pHead, 1) == false)printf("error Delate\n");
	if (print(pHead) == false)printf("print error!\n");
	system("pause");
	return 0;
}