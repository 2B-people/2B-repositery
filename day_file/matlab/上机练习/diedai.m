function [x,y] = diedai(a,b,n)
%迭代公式函数
% a，b ：参数
% n : 迭代次数
x = zeros(1,n);
y = zeros(1,n);
x(1) = rand(1);
y(1) = rand(1);                                                            %init变量

for i= 1:n
    x(i+1) = a*y(i)*sin(x(i));
    y(i+1) = abs(x(i))-b;                                                  %迭代过程
end
end