#include <stdio.h>

int main()
{
    char *num;
    scanf("%s", num);
    for (int i = 0; num[i] != '\0'; i++)
        if (num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9')
            printf("%c", num[i]);
    return 0;
}