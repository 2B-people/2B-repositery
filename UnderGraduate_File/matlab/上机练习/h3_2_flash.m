%homework3_2 ����һ�������Ÿÿռ������˶��Ķ���
clear;
t = 0:0.01:10*pi;                                                          %init��t��

r = 2;                                                                     %����һ����                      
[x,y,z] = sphere;
z = z./(100/3);

figure;
for i = 1:length(t)
    plot3(50.*sin(t),50.*cos(t),0.1.*t);                                   %����ԭͼ��
    axis([-60 60 -60 60 -1 3]);                                            %�趨������
    grid on;
    hold on;
    mesh(r*x+50*sin(t(i)),r*y+50*cos(t(i)),r*z+0.1*t(i));                  %����
    hold off;
    if i == 1                                                              %��һ�εȴ�1s
        pause(1);
    else
        pause(0.00001);                                                    %��һ֡ˢ��ԭͼ��
    end
end