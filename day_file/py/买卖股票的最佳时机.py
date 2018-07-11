'''
假设有一个数组，它的第i个元素是一支给定的股票在第i天的价格。
如果你最多只允许完成一次交易,设计一个算法来找出最大利润。
'''
class Solution:
    def maxProfit1(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #算股市变化表
        NEW[]
        for i in range(len(prices)-1):
            NEW.append(price[i+1]-price[i])
        #子数组最大和
        temp = 0
        imax = 0
        for i in NEW:
            if temp+i>0:
                temp += i
            else:
                temp = 0
            imax = max(temp,imax)
        
        return imax


'''
题目：
用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。
交易次数不限，但一次只能交易一支股票，也就是说手上最多只能持有一支股票，求最大收益。
你可以完成尽可能多的交易(多次买卖股票)。
然而,你不能同时参与多个交易(你必须在再次购买前出售股票)
'''
'''

'''
    def maxProfit2(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max = 0
        for i in range(1,len(prices)):
            if(prices[i]-prices[i-1]>0):
                max+=prices[i]-prices[i-1]
        return max