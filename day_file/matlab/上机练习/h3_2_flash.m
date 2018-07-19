%homework3_2 绘制一粒球沿着该空间曲线运动的动画
clear;
t = 0:0.01:10*pi;                                                          %init（t）

r = 2;                                                                     %生成一个球                      
[x,y,z] = sphere;
z = z./(100/3);

figure;
for i = 1:length(t)
    plot3(50.*sin(t),50.*cos(t),0.1.*t);                                   %画出原图像
    axis([-60 60 -60 60 -1 3]);                                            %设定坐标轴
    grid on;
    hold on;
    mesh(r*x+50*sin(t(i)),r*y+50*cos(t(i)),r*z+0.1*t(i));                  %画球
    hold off;
    if i == 1                                                              %第一次等待1s
        pause(1);
    else
        pause(0.00001);                                                    %过一帧刷新原图像
    end
end