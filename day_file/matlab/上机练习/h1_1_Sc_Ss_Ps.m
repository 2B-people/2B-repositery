%homework1_1          ����cell��
clear;clc;

A = rand(3,4);                                    %����һ��3��4���������A
s=find(A>=0.5);                                    %����A1�д���0.5��λ��

A = uint8(255 * rand(512));                        %512��512���������A��uint8��[0,255]
 
 Cs = cell(1,256);
 Ss = zeros(1,256);
 Ps = zeros(1,256);
 
 %����1��256��Ԫ������Cs������Cs{i}ΪA��ȡֵΪi��Ԫ�صı�ʶ
 for i = 1:256
     Cs{i} = find(A == i);
 end
 %����1��256������Ss������Ss[i]ΪA��ȡֵΪi��Ԫ�صĸ���
 for j = 1:256
     Ss(j) = length(Cs{j});
 end
 %����1��256������Ps������Ps[i]ΪA��ȡֵС�ڵ���i��Ԫ�صĸ�����
 for k = 1:256
     Ps(k) = length(find(A<=k));
 end
 
 
 %1��answer��s�����ݴ�����A������A>=0.5��λ��Ϊ1������Ϊ0