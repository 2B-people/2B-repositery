%homework3_1 一种简单混沌图，
clear;
[x1,y1] = diedai(2,2.5,20000);                                             %function 迭代出x，y
subplot(1,3,1);
plot(x1,y1,'*b');                                                          %初值a=2,b=2.5

[x2,y2] = diedai(2,2.7,20000);                                             %初值a=2,b=2.7
subplot(1,3,2);
plot(x2,y2,'*r');             

[x3,y3] = diedai(2,2.9,20000);                                             %初值a=2,b=2.9
subplot(1,3,3);
plot(x3,y3,'*y');