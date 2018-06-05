
//（7）
int num_char(char *str, char del_char)
{
    int num = 0;

    while (*str != '\0')
    {
        if (*str == del_char)
            num++;
        str++;
    }
    return num;
}

//(8)
void fun(char *str)
{
	char *q = str;
	char *flag_jud = str + 1;

	while (*str != '\0')
	{
		if (*str == '*' && *flag_jud != '*')
			break;
		str++;
		flag_jud++;
	}
	q = flag_jud;
	while (*str != '\0')
	{
		if (*str != '*')
			*q++ = *str;
		str++;
	}
	*q = *str;
}

//(9)

void find_max(char *str)
{
	int  num = 0, i, j;
	char jud = *str,*str1 = str;
	while (*str != '\0')
	{
		if (*str >= jud)
			jud = *str;
		str++;
	}
	for (i = 0,j = 1; *(str1 + i) != '\0'; i++)
	{
		if (*(str1 + i) == jud){
			num++;
		map[j++] = i;
		}
	}
	map[0] = num;
	map[j] = -1;
}


#include <stdio.h>
#include <string.h>

int map[100] = { 0 };



int main()
{
	char s[100],i;
	puts("please input char:");
	scanf("%s", s);
	getchar();
	find_max(s);
	printf("num = %d ", map[0]);
	for (i = 1; *(map+i) != -1; i++)
		printf("%d ", map[i]);
	getchar();
	return 0;
}