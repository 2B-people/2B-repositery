int main()
{
    char *G[10],max[100];
    char len,i;
    scanf_s("%c",&len);
    for(i=0;i<len;i++)
    {
        gets(G[i],100);
		if (i == 0)
			strcpy_s(max,100, G[i]);
        else if(strlen(G[i])>strlen(max))
			strcpy_s(max,100, G[i]);
    }
    puts(max);
    system("pause");
    return 0;
}