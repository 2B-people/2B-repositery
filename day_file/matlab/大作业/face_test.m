%big_homework_1  图像变形技术的实现
clear;clc;

% f = imread('face1.jpg');
% g = imread('face2.jpg');
% or
load face_data.mat;                                                        %导入图片数据

face_obj = VideoWriter('face_test.avi');                                   %定义一个视频对象

open(face_obj);                                                            %打开对象
% for i = 0:0.01:1                                                         %伪代码方式，线性运算
%     h = (1-i).*f+i.*g;
%     writeVideo(face_obj,h);
% end

for i = 0:0.01:1                                                           %matlab函数方式
    h = imlincomb((1-i),f,i,g);
    writeVideo(face_obj,h);                                                %写入一帧图片
end

close(face_obj);                                                           %关闭对象