%homework2_1  方程组
function q = myfun1(p)
% 方程组表达式
% p: [x,y]方程自变量
% q：两个隐匿函数表达
x = p(1);
y = p(2);
q(1)= exp(x)-2*exp(x+y)-50;
q(2)= exp(y)-3*exp(x+y)-80;
end