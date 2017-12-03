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
#define R 4        //蛇的四个状态

/************************************************************/
typedef struct SNAKE//蛇的一个节点
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

/*********************全局变量*******************************/

static snake *head,*food;
static int endgamestatus=0;//游戏的状态
static int status, sleeptime = 200;//每次运行的时间间隔
static snake *q;//遍历蛇身的指针
static int gradesum=0, add = 10;


/*******************函数声明**********************************/

int welcome(void);//欢迎界面
void game(void);//游戏主函数
void ranking_listget(int gradesum);//记录游戏成绩
void ranking_list(void);//英雄表主函数
void Pos(int x, int y);//设置光标位置
void init_map(void);//初始化地图
void init_snake(void);//初始化蛇
void createfood(void);//随机出现食物
void snakemove(void);//蛇前进，上U，下D，左L，右R
void biteself(void);//判断是否咬到自己
void cantcrosswall(void);//不能穿墙
void endgame(void);//游戏结束
void gamecircle(void);//控制游戏
void helplist(void);//帮助菜单，陈述游戏方式