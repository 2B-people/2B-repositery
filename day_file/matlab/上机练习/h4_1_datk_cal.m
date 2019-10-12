%homework4_1 
clear;

% 根据给定的石油价格数据（包含了当时价格与1999年的折算价格），
% 编程计算并绘制其RSI曲线，并在RSI曲线上叠加20-50-80线。

% data = xlsread('oilprice_simple.xls');                                     %导入数据
% year = data(:,1);                                                          
% pday = data(:,2);
% pnow = data(:,3);
% 
% save('oilprice','year','pday','pnow');                                     %数据保存到oilprice.met
% or
load oilprice.mat                                                          %导入数据

datk = zeros(1,15);
rsi = zeros(1,125);
for years = 1875:1999                                                      %迭代年份
    for i = 1:15                                                           %得到当前年份包括前14年的数据
        datk(i) = pnow(ismember(year,years-15+i));
    end
    rsi(years-1874) = calRsiPer(datk);                                     %计算rsi(PS.1875年之前没有足够的数据)
end

 subplot(2,1,1); plot(year,pnow,'-*b');                                    %画价格数据
 xlabel('年份'); ylabel('价格');
 
 t_years = 1875:1999;
 y1 = ones(1,125);
 subplot(2,1,2);plot(t_years,rsi,'-r'...                                   %画RSi图
     ,t_years,20.*y1,'-g',t_years,50.*y1,'-g',t_years,80.*y1,'-g');
  xlabel('年份'); ylabel('RSI(%)');
  
  %价格的选择为折算价格是绘图结果类似题目给出