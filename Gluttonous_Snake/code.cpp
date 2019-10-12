/*@file:code.c
  @author:2B_poeple
  @date:2017.11.12*/

#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include "snake.h"

int welcome(void)
{
	int code = 0,status;
	printf("\n%s\n\n", BEOREND);
	printf("     Welcome to GluttonousSnake!!\n");//选择列表
	printf("     1)New Game;    2)Ranking List;\n");
	printf("     3)HelpList;    4)Endgame;\n");
	printf("\n%s\n\n", BEOREND);
	while ((status = scanf_s("%d", &code)) != 1 || (code < 1 || code>4)) {
		if (status != 1) {
			scanf_s("%*s");//处理非整数输入
		}
		printf("Enter an integer from 1 to 4,please.\n");
	}
	return code;
}

void game(void)
{
	system("cls");
	init_map();
	init_snake();
	createfood();
	gamecircle();
	endgame();
}

void helplist(void)
{
	system("cls");
	printf("\n%s\n\n", BEOREND);
	printf("     Welcome to GluttonousSnake!!\n");//选择列表
	printf("1)这是一个简单的贪吃蛇游戏，\n");
	printf("2)上下左右控制蛇的运动，F1，F2控制蛇的难度，空格可以暂停。\n");
	printf("3)什么也不说了，吃的一个食物可以加分，快来挑战屌炸天的贪吃蛇吧！！\n");
	printf("PS(作者，打二货，哈哈哈哈！！！)");
	printf("\n%s\n\n", BEOREND);
	system("pause");
	system("cls");
}

void Pos(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void init_map(void)
{
	for (int i = 0; i < 50; i++) /*打印竖边框*/{
		Pos(i, 0);
		printf("*" );
		Pos(i, 26);
		printf("*");
	}
	for (int i = 0; i < 26; i++)/*打印横边框*/ {
		Pos(0, i);
		printf("*");
		Pos(50, i);
		printf("*");
	}
}

void init_snake(void)
{
	snake *tail;
	tail = (snake*)malloc(sizeof(snake));//从蛇尾开始，头插法，以X,Y设定开始的位置
	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;
	for (int i = 1; i <= 4; i++) {
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;
		head->y = 5;
		head->x = 24 + 2 * i;
		tail = head;
	}
	while (tail != NULL)//从头到尾，输出蛇身
	{
		Pos(tail->x, tail->y);
		printf("+");
		tail = tail->next;
	}
}

void createfood(void)
{
	snake *food_new;
	srand((unsigned)time(NULL));
	food_new = (snake*)malloc(sizeof(snake));
	while ((food_new->x % 2) != 0)/*保证出现位置在偶数上，使得食物能与蛇头对接*/ {
		food_new->x = rand() % 48 + 2;
	}
	food_new->y = rand() % 24 + 1;
	q = head;
	while (q->next == NULL)
	{
		if (q->x == food_new->x&&q->y == food_new->y) {
			free(food_new);
			createfood();
		}
		q = q->next;
	}
	Pos(food_new->x, food_new->y);
	food = food_new;
	printf("#");
}

void snakemove(void)
{
	snake *nexthead;
	cantcrosswall();
	biteself();
	nexthead=(snake*)malloc(sizeof(snake));
	if (status == U)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
		if (nexthead->x == food->x&&nexthead->y == food->y) //如果有食物
		{
			gradesum += add;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL) {
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			createfood();
		}
		else       //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while ((q->next)->next != NULL)
			{
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
		}
	}

	if (status == D)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == food->x&&nexthead->y == food->y) //如果有食物
		{
			gradesum += add;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL) {
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			createfood();
		}
		else       //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (status == L)
	{
		nexthead->x = head->x-2;
		nexthead->y = head->y;
		if (nexthead->x == food->x&&nexthead->y == food->y) //如果有食物
		{
			gradesum += add;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL) {
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			createfood();
		}
		else       //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (status == R)
	{
		nexthead->x = head->x+2;
		nexthead->y = head->y;
		if (nexthead->x == food->x&&nexthead->y == food->y) //如果有食物
		{
			
			gradesum += add; 
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL) {
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
		createfood();
		}
		else       //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("+");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
}

void gamecircle(void)
{
	status = R;
	while (endgamestatus==0)
	{
		if (GetAsyncKeyState(VK_UP) && status != D)
			status = U;
		if (GetAsyncKeyState(VK_DOWN) && status != U)
			status = D;
		if (GetAsyncKeyState(VK_LEFT) && status != R)
			status = L;
		if (GetAsyncKeyState(VK_RIGHT) && status != L)
			status = R;
		if (GetAsyncKeyState(VK_F1)) {
			if (sleeptime >= 50) {
				sleeptime = sleeptime - 30;
				add = add + 2;
				if (sleeptime == 320)
				{
					add = 2;//防止减到1之后在加有错
				}
			}
		}
		if (GetAsyncKeyState(VK_F2)){
			if (sleeptime < 350){
				sleeptime = sleeptime + 30;
				add = add - 2;
				if (sleeptime == 350) {
					add = 1;//保证最低分为1
				}
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			while (1) {
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))
					break;
			}
		}
		if (GetAsyncKeyState(VK_F3)) {
			endgamestatus = 3;
			break;
		}
		Sleep(sleeptime);
		snakemove();
	}
}

void biteself(void)
{
	snake *self;
	self = head->next;
	while (self != NULL)
	{
		if (self->x == head->x && self->y == head->y)
			endgamestatus = 2;
		self = self->next;
	}
}

void cantcrosswall()
{
	if (head->x == 0 || head->x == 50 || head->y == 0 || head->y == 26)
	{
		endgamestatus = 1;
	}
}

void endgame(void)
{
	system("cls");
	Pos(5, 10);
	printf("GAME OVER!!\n");
	Pos(5, 11);
	if (endgamestatus == 1)printf("你撞墙了！！");
	if (endgamestatus == 2)printf("你碰到自己了！！");
	if (endgamestatus == 3)printf("你自己结束了游戏！！");
	Pos(5, 12);
	printf("你的得分是：%d", gradesum);
	Pos(5, 13);
	//int judge=0;
	//printf("你是否希望将你的成绩记录在英雄榜上？如果是，请Q1：");
	//scanf_s("%d", &judge);
	//if (judge==1)
	//{
	//	ranking_listget(gradesum);
	//}
	//else {
		system("pause");
		system("cls");
		gradesum = 0;
		endgamestatus = 0;
		sleeptime = 200;
	//}
}

void ranking_listget(int gradesum)
{
	while (1);
}

void ranking_list(void)
{
	while (1);
}
