#include<stdio.h>

int binary(int *data,int key,int l);

int main(void)
{
    int data[]={1,2,3,4,5,6,7,8,9,12,13,45,67,89,99,101,111,123,134,565,677};
    int b[]={677,1,7,117};
    for(int i=0;i<sizeof(b);i++)
        printf("%d\n",binary(data,b[i],sizeof(data)/sizeof(data[0])));
    return 0;
}

int binary(int *data,int key,int len)
{
    int left=0,right=len-1,mid=0;
    mid=(left+right)/2;
    while(left<right&&data[mid]!=key)
    {
        if(data[mid]<key)//缩小搜索范围
            left=mid+1;
        else if(data[mid]>key)
            right=mid-1;
        mid=(left+right)/2;    
    }
    if(data[mid]==key)
        return mid;
    return -1;
}