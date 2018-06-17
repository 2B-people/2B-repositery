#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 100
#define MOD 1000
char a[MAXN];
int main(int argc, char *argv[])
{
	int i, j;
	int fin, fina = 0, finb = 0;
	while (scanf("%s", a)==1 ) {
		for (i = 0; i < strlen(a); i++) {
			if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				for (j = 0; j < i; j++) {
					fina = fina * 10 + a[j] - '0';
				}
				for (j = i + 1; j < strlen(a); j++) {
					finb = finb * 10 + a[j] - '0';
				}
				//printf("fina=%d\nfinb=%d\n", fina, finb);
				if (a[i] == '/'&&finb == 0.0) {
					printf("The divisor can't be zero");
					system("pause");
				}
				if (a[i] == '+')fin = fina + finb;
				if (a[i] == '-')fin = fina + finb;
				if (a[i] == '*')fin = fina * finb;
				if (a[i] == '/'&&finb != 0.0)fin = fina / finb;
				fina = finb = 0;
			}
		}
		printf("=%d\n", fin);
	}
	return 0;
}