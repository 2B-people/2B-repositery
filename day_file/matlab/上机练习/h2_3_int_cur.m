%homework2_3  空间曲线第一类积分
clear;
syms x y z t f                                                             %符号定义                  

x = 3*t;                                                                   %曲线系数方程组
y = 3*t^2;
z = 2*t^3;

f = sqrt(diff(x)*diff(x)+diff(y)*diff(y)+diff(z)*diff(z));                 %第一类曲线积分表达式

q = double(int(f,t,0,1));                                                  %积分
disp(q)