#include<stdio.h>
int main()
{
	int answer = 0;
	for (answer = 'a'; answer <= 'd'; answer ++ ) {
		if ((answer != 'a') + (answer == 'c') + (answer == 'd')+( answer!='d' )==3) {
			printf("killer is %c", answer);
		}
	}
	return 0;
}