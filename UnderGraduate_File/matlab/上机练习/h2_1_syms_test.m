%homework2_1   非线性方程的解析解
clear;

syms x y 
eq1 = exp(x)-2*exp(x+y)==50;
eq2 = exp(y)-3*exp(x+y)==80;
s = solve(eq1,eq2);                                                        %解析解（solve）
digits(5);                                                                 %有效位设置为5
A_s{1} = vpa(s.x);         
A_s{2} = vpa(s.y);

%设置初值为(0.1+0.1i,0.1+0.1i)与(0.1-0.1i,0.1-0.1i)，求其数值解（fsolve）
A_f{1} = fsolve(@myfun1,[0.1+0.1i 0.1+0.1i],optimset('Display','off'));  
A_f{2} = fsolve(@myfun1,[0.1-0.1i 0.1-0.1i],optimset('Display','off'));

%3）fsolve与solve在使用方式上不同。