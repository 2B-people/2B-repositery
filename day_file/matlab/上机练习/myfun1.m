%homework2_1  ������
function q = myfun1(p)
% ��������ʽ
% p: [x,y]�����Ա���
% q���������亯�����
x = p(1);
y = p(2);
q(1)= exp(x)-2*exp(x+y)-50;
q(2)= exp(y)-3*exp(x+y)-80;
end