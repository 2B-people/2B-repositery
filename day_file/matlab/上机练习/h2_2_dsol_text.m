%homework2_2  微分方程通解和解析解
clear;

syms y(t)
eqn = diff(y,t,2)-2*diff(y,t) == 3*y;                                      %表达式
dsol = dsolve(eqn);                                                        %其通解
disp(dsol);

t_dsol = dsolve(eqn,y(0)==0,y(1)== 1);                                     %初值条件y(0)=0，y(1)=1的特解
ezplot(t_dsol,[-6,2]);                                                     %并在[-6 2]范围内绘制解函数曲线

