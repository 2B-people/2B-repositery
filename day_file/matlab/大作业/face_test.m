%big_homework_1  ͼ����μ�����ʵ��
clear;clc;

% f = imread('face1.jpg');
% g = imread('face2.jpg');
% or
load face_data.mat;                                                        %����ͼƬ����

face_obj = VideoWriter('face_test.avi');                                   %����һ����Ƶ����

open(face_obj);                                                            %�򿪶���
% for i = 0:0.01:1                                                         %α���뷽ʽ����������
%     h = (1-i).*f+i.*g;
%     writeVideo(face_obj,h);
% end

for i = 0:0.01:1                                                           %matlab������ʽ
    h = imlincomb((1-i),f,i,g);
    writeVideo(face_obj,h);                                                %д��һ֡ͼƬ
end

close(face_obj);                                                           %�رն���