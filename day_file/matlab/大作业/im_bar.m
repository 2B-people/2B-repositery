%big_homework_2  图像的直方图均衡
clear;clc;

% obj = imread('image1.jpg');
% [row,col] = length(obj);
% or
load image1_data.mat;                                                      %导入数据

for i= 0:255                                                               %计算直方图
ni = length(find(obj == i));                                               %计算im上i出现的次数ni；
p1(i+1) = ni/(row*col);
end

c = cumsum(p1);                                                            %计算累计直方图

subplot(2,2,1);    imshow(obj);                                            %画图
subplot(2,2,2);    bar(p1,'r');                                             
ylabel('Number of occurances');
xlabel('Greyscale value');


for s1 = 1:row                                                             %进行变换处理
    for s2 = 1:col 
        i = obj(s1,s2);                                                    %读取原图像对应位置的灰度值i;
        imnew(s1,s2) = c(i+1);                                             %进行变换
    end
end
imnew = uint8(255.*imnew);

for i= 0:255                                                               %计算imnew的直方图
ni = length(find(imnew == i));
p2(i+1) = ni/(row*col);
end

subplot(2,2,3);    imshow(imnew);                                          %画图
subplot(2,2,4);    bar(p2,'r'); 
ylabel('Number of occurances');
xlabel('Greyscale value');