#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	char G[100];
	gets(G);
	G[0] = G[0] + ('A' - 'a');
	for (i = 0; G[i] != '\0'; i++)
	{
		if (G[i] == ' ')G[i + 1] = G[i+1] + ('A' - 'a');
	}
	printf("%s", G);
	system("pause");
	return 0;
}
