'''
给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
'''

class Solution:
    #56ms,mine
    def plusOne1(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = 1
        sum = 0
        for data in digits:
            sum = sum + data*(10**(len(digits)-i))
            i = i+1
        sum = int(sum + 1)
        # print(sum)

        list = []

        while sum > 0:
            list.append(sum % 10)
            sum = sum // 10

        list.reverse()
        #print(list)
        return list
    # 36ms
    def plusOne2(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """ 
        result=[]
        if digits[-1]!=9:
            digits[-1]=digits[-1]+1
            result=digits
        else:
            num=0
            digits.reverse()
            for i in range(len(digits)):
                num=num+digits[i]*(10**(i))
            num=str(num+1)
            for j in num:
                result.append(int(j))
        return result
    

sol = Solution()
print(sol.plusOne1([1,2,3,4,3,1,6,5,4,7,8,9,4,2,4,6]))