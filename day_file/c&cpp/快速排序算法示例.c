#include <stdio.h> 
int data[101],n;//定义全局变量，这两个变量需要在子函数中使用 
void quicksort(int left,int right) 
{ 
    int i,j,temp; 
    if(left>right) 
       return; 
                                
    temp=data[left]; //temp中存的就是基准数 
    i=left; 
    j=right; 
    while(i!=j) 
    { 
                   //顺序很重要，要先从右边开始找 
                   while(data[j]>=temp && i<j) 
                            j--; 
                   //再找右边的 
                   while(data[i]<=temp && i<j) 
                            i++; 
                   //交换两个数在数组中的位置 
                   if(i<j) 
                   { 
                       data[i]=data[i]^data[j];
                       data[j]=data[i]^data[j];
                       data[i]=data[i]^data[j];
                   } 
    } 
    //最终将基准数归位 
    data[left]=data[i]; 
    data[i]=temp; 
                             
    quicksort(left,i-1);//继续处理左边的，这里是一个递归的过程 
    quicksort(i+1,right);//继续处理右边的 ，这里是一个递归的过程 
} 
int main() 
{ 
    int n; 
    //读入数据 
    scanf("%d",&n); 
    for(int i=0;i<n;i++) 
       scanf("%d",&data[i]); 

    quicksort(1,n); //快速排序调用 
                             
    //输出排序后的结果 
    for(int i=0;i<n;i++) 
        printf("%d ",data[i]); 
    getchar();getchar(); 
    return 0; 
}