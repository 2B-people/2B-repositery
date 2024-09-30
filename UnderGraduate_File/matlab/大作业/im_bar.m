%big_homework_2  ͼ���ֱ��ͼ����
clear;clc;

% obj = imread('image1.jpg');
% [row,col] = length(obj);
% or
load image1_data.mat;                                                      %��������

for i= 0:255                                                               %����ֱ��ͼ
ni = length(find(obj == i));                                               %����im��i���ֵĴ���ni��
p1(i+1) = ni/(row*col);
end

c = cumsum(p1);                                                            %�����ۼ�ֱ��ͼ

subplot(2,2,1);    imshow(obj);                                            %��ͼ
subplot(2,2,2);    bar(p1,'r');                                             
ylabel('Number of occurances');
xlabel('Greyscale value');


for s1 = 1:row                                                             %���б任����
    for s2 = 1:col 
        i = obj(s1,s2);                                                    %��ȡԭͼ���Ӧλ�õĻҶ�ֵi;
        imnew(s1,s2) = c(i+1);                                             %���б任
    end
end
imnew = uint8(255.*imnew);

for i= 0:255                                                               %����imnew��ֱ��ͼ
ni = length(find(imnew == i));
p2(i+1) = ni/(row*col);
end

subplot(2,2,3);    imshow(imnew);                                          %��ͼ
subplot(2,2,4);    bar(p2,'r'); 
ylabel('Number of occurances');
xlabel('Greyscale value');