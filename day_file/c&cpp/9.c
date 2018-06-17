#include <stdio.h>
#include <math.h>

#define MAX 10
#define MIN -10
#define f(x) 2 * x *x *x - 4 * x *x + 3 * x - 6

int main()
{
    double x, left = MIN, right = MAX;
    do
    {
        x = (left + right) / 2;
        if (f(x) * f(right) < 0)
            left = x;
        else
            right = x;
    } while (f(x) > pow(10.0, -5) || f(x) < -1 * pow(10.0, -5));
    printf("%.1lf", x);
    return 0;
}