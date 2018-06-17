#include<Stdio.h>

int mian()
{
	char str[50];
	char ch;
	int j=0;
	scanf("%s",str);
	scanf("%c",ch);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!=ch)
			str[j++]=str[i];
	}
	str[j]='\0';
	printf("%s",str);
	return 0;
}