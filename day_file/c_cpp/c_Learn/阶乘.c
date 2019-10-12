#include<stdio.h>
#include<stdlib.h>

int jiechen(int num);

int main(void)
{
	int num = 10;
	printf("10!=%d\n", jiechen(num));
	system("pause");
	return 0;
}

int jiechen(int num) /*阶乘函数*/{
	int result;
	for(result=0;num>1;num--)
		result *= num ;
	return result;
}
