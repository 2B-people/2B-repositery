%homework2_1   �����Է��̵Ľ�����
clear;

syms x y 
eq1 = exp(x)-2*exp(x+y)==50;
eq2 = exp(y)-3*exp(x+y)==80;
s = solve(eq1,eq2);                                                        %�����⣨solve��
digits(5);                                                                 %��Чλ����Ϊ5
A_s{1} = vpa(s.x);         
A_s{2} = vpa(s.y);

%���ó�ֵΪ(0.1+0.1i,0.1+0.1i)��(0.1-0.1i,0.1-0.1i)��������ֵ�⣨fsolve��
A_f{1} = fsolve(@myfun1,[0.1+0.1i 0.1+0.1i],optimset('Display','off'));  
A_f{2} = fsolve(@myfun1,[0.1-0.1i 0.1-0.1i],optimset('Display','off'));

%3��fsolve��solve��ʹ�÷�ʽ�ϲ�ͬ��