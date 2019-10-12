
'''
题目：
用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。
交易次数不限，但一次只能交易一支股票，也就是说手上最多只能持有一支股票，求最大收益。
你可以完成尽可能多的交易(多次买卖股票)。
然而,你不能同时参与多个交易(你必须在再次购买前出售股票)
'''

# TODO add 股票交易2解决方案

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max = 0
        for i in range(1,len(prices)):
            if prices[i]-prices[i-1]>0:
                max+=prices[i]-prices[i-1]
        return max