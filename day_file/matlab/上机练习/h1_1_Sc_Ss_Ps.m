%homework1_1          矩阵，cell，
clear;clc;

A = rand(3,4);                                    %创建一个3×4的随机矩阵A
s=find(A>=0.5);                                    %矩阵A1中大于0.5的位置

A = uint8(255 * rand(512));                        %512×512的随机矩阵A，uint8，[0,255]
 
 Cs = cell(1,256);
 Ss = zeros(1,256);
 Ps = zeros(1,256);
 
 %构建1×256的元胞数组Cs，其中Cs{i}为A中取值为i的元素的标识
 for i = 1:256
     Cs{i} = find(A == i);
 end
 %构建1×256的数组Ss，其中Ss[i]为A中取值为i的元素的个数
 for j = 1:256
     Ss(j) = length(Cs{j});
 end
 %构建1×256的数组Ps，其中Ps[i]为A中取值小于等于i的元素的个数。
 for k = 1:256
     Ps(k) = length(find(A<=k));
 end
 
 
 %1）answer：s的数据代表这A矩阵中A>=0.5的位置为1，其余为0