#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char one, char two, char three);
void move(char x, char y);

int main()
{
	int m;
	printf("input: ");
	scanf_s("%d", &m);
	hanoi(m, 'A', 'B', 'C');
	system("pause");
	return 0;
}

void hanoi(int n, char one, char two, char three)
{
	if (n == 1)
		move(one, three);
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}
 
void move(char x, char y)
{
	printf("%c-->%c\n", x, y);
}