%homework2_3  �ռ����ߵ�һ�����
clear;
syms x y z t f                                                             %���Ŷ���                  

x = 3*t;                                                                   %����ϵ��������
y = 3*t^2;
z = 2*t^3;

f = sqrt(diff(x)*diff(x)+diff(y)*diff(y)+diff(z)*diff(z));                 %��һ�����߻��ֱ��ʽ

q = double(int(f,t,0,1));                                                  %����
disp(q)