%homework3_1 һ�ּ򵥻���ͼ��
clear;
[x1,y1] = diedai(2,2.5,20000);                                             %function ������x��y
subplot(1,3,1);
plot(x1,y1,'*b');                                                          %��ֵa=2,b=2.5

[x2,y2] = diedai(2,2.7,20000);                                             %��ֵa=2,b=2.7
subplot(1,3,2);
plot(x2,y2,'*r');             

[x3,y3] = diedai(2,2.9,20000);                                             %��ֵa=2,b=2.9
subplot(1,3,3);
plot(x3,y3,'*y');