%homework1_2   ����С���˷������������
clear;

x = [0.50 1.00 1.50 2.00 2.50 3.00];                                       %ԭʼ����
y = [1.75 2.45 3.81 4.80 8.00 8.60];
xi = 0:0.1:3;

p2 = polyfit(x,y,2);                                                       %���׶���ʽ���
yi2 = polyval(p2,xi);
err(2) =sum((y-yi2(ismember(xi,x))).^2);                                   %����λ���ҵ���Ӧyi
%plot(xi,yi2,x,y,'r*');
 
p1 = polyfit(x,y,1);                                                       %һ��
yi1 = polyval(p1,xi);
err(1) =sum((y-yi1(ismember(xi,x))).^2);

p3 = polyfit(x,y,3);                                                       %����
yi3 = polyval(p3,xi);
err(3) =sum((y-yi3(ismember(xi,x))).^2);

plot(x,y,'*r',xi,yi1,'-k',xi,yi2,'-b',xi,yi3,'-m');                        %��ͼ
 
switch(find(err == min(err)))                                              %�Ƚ�err
    case 1
        disp('һ����������С');
    case 2
        disp('������������С');
    case 3
        disp('������������С');
end