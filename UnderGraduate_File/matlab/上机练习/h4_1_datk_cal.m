%homework4_1 
clear;

% ���ݸ�����ʯ�ͼ۸����ݣ������˵�ʱ�۸���1999�������۸񣩣�
% ��̼��㲢������RSI���ߣ�����RSI�����ϵ���20-50-80�ߡ�

% data = xlsread('oilprice_simple.xls');                                     %��������
% year = data(:,1);                                                          
% pday = data(:,2);
% pnow = data(:,3);
% 
% save('oilprice','year','pday','pnow');                                     %���ݱ��浽oilprice.met
% or
load oilprice.mat                                                          %��������

datk = zeros(1,15);
rsi = zeros(1,125);
for years = 1875:1999                                                      %�������
    for i = 1:15                                                           %�õ���ǰ��ݰ���ǰ14�������
        datk(i) = pnow(ismember(year,years-15+i));
    end
    rsi(years-1874) = calRsiPer(datk);                                     %����rsi(PS.1875��֮ǰû���㹻������)
end

 subplot(2,1,1); plot(year,pnow,'-*b');                                    %���۸�����
 xlabel('���'); ylabel('�۸�');
 
 t_years = 1875:1999;
 y1 = ones(1,125);
 subplot(2,1,2);plot(t_years,rsi,'-r'...                                   %��RSiͼ
     ,t_years,20.*y1,'-g',t_years,50.*y1,'-g',t_years,80.*y1,'-g');
  xlabel('���'); ylabel('RSI(%)');
  
  %�۸��ѡ��Ϊ����۸��ǻ�ͼ���������Ŀ����