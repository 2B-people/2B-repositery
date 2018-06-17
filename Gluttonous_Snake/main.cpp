/*@file:main.c
  @author:2B_poeple
  @date:2017.11.12
  @brief
  */
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include"snake.h"

int main()
{
	int code=0;
	while ((code = welcome()) != QUIT) {
		switch (code)
		{
		case 1: game();
			break;
		case 2:// ranking_list();
			break;
		case 3:helplist();
			break;
		default:printf("big bug!");
			break;
		}
	}
	return 0;
}