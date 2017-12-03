/*@file:snake.h
  @author:2B_poeple
  @date:2017.11.12
  */

#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

#define BEOREND "**********************************************************"
#define QUIT 4
#define U 1
#define D 2
#define L 3
#define R 4        //�ߵ��ĸ�״̬

/************************************************************/
typedef struct SNAKE//�ߵ�һ���ڵ�
{
	int x;
	int y;
	struct SNAKE *next;
}snake;

typedef struct GRADE
{
	char name[20];
	int grade;
}grade;

/*********************ȫ�ֱ���*******************************/

static snake *head,*food;
static int endgamestatus=0;//��Ϸ��״̬
static int status, sleeptime = 200;//ÿ�����е�ʱ����
static snake *q;//���������ָ��
static int gradesum=0, add = 10;


/*******************��������**********************************/

int welcome(void);//��ӭ����
void game(void);//��Ϸ������
void ranking_listget(int gradesum);//��¼��Ϸ�ɼ�
void ranking_list(void);//Ӣ�۱�������
void Pos(int x, int y);//���ù��λ��
void init_map(void);//��ʼ����ͼ
void init_snake(void);//��ʼ����
void createfood(void);//�������ʳ��
void snakemove(void);//��ǰ������U����D����L����R
void biteself(void);//�ж��Ƿ�ҧ���Լ�
void cantcrosswall(void);//���ܴ�ǽ
void endgame(void);//��Ϸ����
void gamecircle(void);//������Ϸ
void helplist(void);//�����˵���������Ϸ��ʽ