%homework5_1 ��ֵ-���-��ֵ����

clear;clc;
load h_5_data;                                                             %������Ŀ����
%or
% x = 1:3;   y = 1:5;
% z = [82 79 84 ; 81 63 84 ; 80 61 82 ; 82 65 85 ; 84 81 86];

xi = 1:0.2:3;
yi = 1:0.2:5;
[xii,yii] = meshgrid(xi,yi);                                               %��xi��yi�ſ�������      
zii = interp2(x,y,z,xii,yii,'cubic');                                      %��ֵ

mesh(xii,yii,zii);                                                         %mush��ͼ

hold on                                                                    %���ԭ���ݵ�
[xx,yy] = meshgrid(x,y);
plot3(xx,yy,z,'*r'); 
disp('file fun success!')
hold off
