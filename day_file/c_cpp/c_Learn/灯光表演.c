/*
Problem Description
郝建为了追求女神，苦学计算机网络技术，并且成功黒入了杭电图书馆的电力调度系统。
为了制造迷幻的灯光效果，他写了一个程序来控制图书馆每个房间灯光的开关。
他把所有的N个房间按照1～N进行编号，初始时所有房间的灯都亮着。
接下来K秒种，第i秒时改变所有房间编号为i的倍数的灯的状态。
换言之，第1秒熄灭所有房间的灯；第2秒点亮所有房间编号为2的倍数的灯；第3秒改变所有房间编号为3的倍数的灯的状态：
原来亮着的灯将被熄灭，而熄灭的灯将被点亮，以此类推。你的任务是，计算K秒后仍然开着灯的房间的编号。 
Input
输入分两行，每行一个整数。第一个数为房间数量N（0<N<=1000），第二个数为经过的秒钟数K（0<K<=1000）。
Output
输出只有一行，为K秒后亮着灯的房间编号。每个数字之间用一个空格隔开,行尾不能有多余空格和回车。
 */

 #include<stdio.h>
 
 int main()
 {
     char G[1000] = { 0 };
     int jud = 0;
     int N, i, j, k;
     scanf("%d", &N);
     scanf("%d", &k);
 	for (i = 2; i<=k; i++)
        for (j = i-1; j<=N; j++)
        {
          if ((j+1) % i  == 0)
            {
                if (G[j ] == 0)
                    G[j ] = 1;
                else
                    G[j ] = 0;
            }
        }
     for (i = 0; i<N; i++)
     {
         if (G[i] == 1)
         {
             if (jud == 0)
             {
                 printf("%d", i + 1);
                 jud = 1;
             }
             else
             {
                 printf(" %d", i + 1);
             }
         }
     }
     return 0;
 }