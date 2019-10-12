%homework1_2   用最小二乘法拟合下列数据
clear;

x = [0.50 1.00 1.50 2.00 2.50 3.00];                                       %原始数据
y = [1.75 2.45 3.81 4.80 8.00 8.60];
xi = 0:0.1:3;

p2 = polyfit(x,y,2);                                                       %二阶多项式拟合
yi2 = polyval(p2,xi);
err(2) =sum((y-yi2(ismember(xi,x))).^2);                                   %利用位置找到对应yi
%plot(xi,yi2,x,y,'r*');
 
p1 = polyfit(x,y,1);                                                       %一阶
yi1 = polyval(p1,xi);
err(1) =sum((y-yi1(ismember(xi,x))).^2);

p3 = polyfit(x,y,3);                                                       %三阶
yi3 = polyval(p3,xi);
err(3) =sum((y-yi3(ismember(xi,x))).^2);

plot(x,y,'*r',xi,yi1,'-k',xi,yi2,'-b',xi,yi3,'-m');                        %画图
 
switch(find(err == min(err)))                                              %比较err
    case 1
        disp('一阶拟合误差最小');
    case 2
        disp('二阶拟合误差最小');
    case 3
        disp('三阶拟合误差最小');
end