%homework2_2  ΢�ַ���ͨ��ͽ�����
clear;

syms y(t)
eqn = diff(y,t,2)-2*diff(y,t) == 3*y;                                      %���ʽ
dsol = dsolve(eqn);                                                        %��ͨ��
disp(dsol);

t_dsol = dsolve(eqn,y(0)==0,y(1)== 1);                                     %��ֵ����y(0)=0��y(1)=1���ؽ�
ezplot(t_dsol,[-6,2]);                                                     %����[-6 2]��Χ�ڻ��ƽ⺯������

