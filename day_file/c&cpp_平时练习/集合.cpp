#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *ss =  (int *)malloc(n*sizeof(int));
    for(int i = 0;i<n+m;i++)
        scanf("%d",ss+i);
    sort(ss,ss+n+m);

    int temp;
    if(n+m >= 1)
    {
        printf("%d",ss[0]);
        temp = ss[0];
    }
    for(int i = 1;i<n+m;i++)
    {
        if(ss[i] == temp)continue;
        printf(" %d",ss[i]);
        temp = ss[i];
    }

    return 0;
}