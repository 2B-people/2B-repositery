function [x,y] = diedai(a,b,n)
%������ʽ����
% a��b ������
% n : ��������
x = zeros(1,n);
y = zeros(1,n);
x(1) = rand(1);
y(1) = rand(1);                                                            %init����

for i= 1:n
    x(i+1) = a*y(i)*sin(x(i));
    y(i+1) = abs(x(i))-b;                                                  %��������
end
end