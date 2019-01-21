#include<stdio.h>
#include<string.h>

int main()
{
    char G[10][50];
    int len;
    for(int i=0;i<len;i++)
        fgets(G[i],50,stdin);
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
    {
        if(stricmp(G[j],G[i])>0)
            strcpy(G[i],G[j]);
    }
    for(int i=0;i<len;i++)
    {
        fputs(G[i],stdout);
    }
    system("pause");
    return 0;
}  