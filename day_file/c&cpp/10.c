#include <stdio.h>
#include <math.h>

int main()
{
    double num, esp, sum = 0;
    char sign = 1;

    scanf("%lf", &esp);
    for (int i = 1;; i++)
    {
        if (abs(num) < esp)
            break;
        num = sign / (3 * i - 2);
        sum += num;
        sign = -sign;
    }
    printf("%lf\n", sum);
    return 0;
}