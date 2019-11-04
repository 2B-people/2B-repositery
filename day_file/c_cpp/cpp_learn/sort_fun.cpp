#include <iostream>
#include "sort_fun.h"

using namespace std;

bool BubbleSort::SortFun(int *data)
{
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
  {
    bool flag = false;
    for (int j = sizeof(data) - 1; j >= i; j--)
    {
      if(data[j] < data[j-1])
      {
        int temp = data[j];
        data[j] = data[j-1];
        data[j-1] =  data[j];
        flag = true;
      }
      if(!flag)
       return true;
    }
  }
}

int *generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);
	
	int *arr = new int[n]; // 创建一个 n个元素的数组
	
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}

int main(int argc, char const *argv[])
{
  int *data = generateRandomArray(1000,1,100);

  BubbleSort test_bubble(data);

  test_bubble.SortLoop();
}