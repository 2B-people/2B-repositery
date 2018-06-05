/* 
题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。
例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。 
程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。 
*/
#include<stdio.h>
#include<math.h>


//输入一个整数，判断此整数是否为水仙花数，是则返回1，否则0
int judge(int number) {
	int ge, shi, bai;
	int forjudge1 = number;
	bai = number / 100;//百位
	number = number % 100;
	shi = number / 10;//十位
	ge = number % 10;//个位
	int forjudge2 = pow(bai, 3) + pow(shi, 3) + pow(ge, 3);
	if (forjudge1 == forjudge2)
		return 1;
	return 0;
}

int main()
{
	int MIN,MAX,jud=1;;
	scanf("%d %d",&MIN,&MAX);
	for (int i = MIN; i < MAX; i++) {
		int forjudge = judge(i);
		if (forjudge == 1) {
			printf(" %d ", i);
			jud=0;
		}
	}
	if(jud)
		printf("no");
	return 0;
}
