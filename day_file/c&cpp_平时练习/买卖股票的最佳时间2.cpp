/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1:
输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
*/



//.c
int maxProfit(int* prices, int pricesSize) {
    int sum = 0;
    for(int i = 0; i<pricesSize-1;i++)
    {
        if(prices[i+1]-prices[i]>0)
            sum += prices[i+1]-prices[i];
    }
    return sum;
}

//.cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
            {
                res = res + prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

//最优解
int maxProfit(int* prices, int pricesSize) {
    int result=0,tmp_min=0,tmp_sub=0;
    for(int i=0;i<pricesSize;i++){
        if(i==0)
            tmp_min=prices[i];
        else if((prices[i]-tmp_min)<=tmp_sub){
            result += tmp_sub;
            tmp_sub = 0;
            tmp_min = prices[i] ;
        }
        else
            tmp_sub= prices[i]-tmp_min;
    }
    return result+tmp_sub;
}