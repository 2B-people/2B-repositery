%homework5_1 插值-拟合-数值积分

clear;clc;
load h_5_data;                                                             %导入题目数据
%or
% x = 1:3;   y = 1:5;
% z = [82 79 84 ; 81 63 84 ; 80 61 82 ; 82 65 85 ; 84 81 86];

xi = 1:0.2:3;
yi = 1:0.2:5;
[xii,yii] = meshgrid(xi,yi);                                               %将xi，yi张开成网格      
zii = interp2(x,y,z,xii,yii,'cubic');                                      %插值

mesh(xii,yii,zii);                                                         %mush画图

hold on                                                                    %标出原数据点
[xx,yy] = meshgrid(x,y);
plot3(xx,yy,z,'*r'); 
disp('file fun success!')
hold off
