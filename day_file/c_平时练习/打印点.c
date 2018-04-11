#include<stdio.h>
#include<stdlib.h>
#define NUMSTAR 2*i-1

int main()
{
	for (int i = 1; i<=4; i++) {
		for (int j = 0; j <= (7 - NUMSTAR) / 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < NUMSTAR; j++) {
			printf("*");
		}
		for (int j = 0; j < (7-NUMSTAR)/2; j++) {
			printf(" ");
		}
		printf("\n");
	}
	for (int i = 3; i >=1; i--) {
		for (int j = 0; j <= (7 - NUMSTAR) / 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < NUMSTAR; j++) {
			printf("*");
		}
		for (int j = 0; j < (7 - NUMSTAR) / 2; j++) {
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}