#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char G[100];
	int i,j ,num=0;
	scanf_s("%s", G,100);
	if (strlen(G) % 2 == 0) {
		for (i = 0,j=strlen(G)-1; i<strlen(G) / 2; i++,j--)
		{
			if (G[i] == G[j])num++;
		}
		if (num == strlen(G)/2)printf("yes");
		else printf("no");
	}
	else if (strlen(G) % 2 != 0) {
		for (i = 0,j=strlen(G)-1; i<(strlen(G) - 1) / 2; i++,j--)
		{
			if (G[i] == G[j])num++;
		}
		if (num == (strlen(G)-1)/2)printf("yes");
		else printf("no");
	}
	system("pause");
	return 0;
}