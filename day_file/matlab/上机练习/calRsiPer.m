%homework4_1  编程实现计算RSI的函数

function rsi=calRsiPer(datK)
% 如何工作
% RSI的计算方法为：
% 以14年RSI指标为例，从当年起算，倒推包括当年在内的15个价格，以每一年的价格减去上一年的价格，
% 得到14个数值，这些数值有正有负。这样，RSI指标的计算公式具体如下：
% A=14个数字中正数之和；
% B=14个数字中负数之和乘以（—1）；
% RSI（14）=A÷（A＋B）×100
% 式中：A为14年中价格向上波动的大小
% B为14年中价格向下波动的大小
% A＋B为价格总的波动大小
% RSI的计算公式实际上就是反映了某一阶段价格上涨所产生的波动占总的波动的百分比率，
% 百分比越大，强势越明显；百分比越小，弱势越明显

% datK：k年的价格数据
% rsi: datK对应的rsi值

    err = zeros(1,14)
    for i = 1:14
        err(i) = datK(i+1)-datK(i);
    end
    A = 0;
    B = 0;
    for n = err
        if n>=0
            A=A+n;
        else
            B=B+n;
        end
    end
    B = -1*B;
    rsi = A/(A+B)*100;
end
