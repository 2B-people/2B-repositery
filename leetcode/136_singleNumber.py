'''
给定一个非空整数数组，除了某个元素只出现一次以外，其余"每个元素均出现两次"。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
'''
import numpy as np

class Solution:

    #me 144ms
    '''
    算法：先将数组排序，排序之后遍历数组，数组中的一个数不同于他的前一位和后一位，这个数就是要找的那个数
        特殊位置，[0]只有后一位，和后一位比，[len(nums)]及最后一位只有前一位，和前一位比。
    缺点：时间复杂度（暂时不会算）
    '''
    def singleNumber1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        nums.sort()
        for i in range(len(nums)):
            if i == 0 and nums[i] != nums[i+1]:
                return nums[i]
            elif i == len(nums)-1 and nums[i] != nums[i-1]:
                return nums[i]
            elif nums[i-1] != nums[i] and nums[i] != nums[i+1]:
                return nums[i]

    #56ms
    '''
    算法：利用python的in运算符，判断元素是否在数组中，并且把元素作为下标，记录元素个数，最后输出个数为1的
        下标。
    缺点：数组长度要求，如果出现一个很大的数，有许多空间被浪费。
    '''
    def singleNumber2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d={}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        #return d
        for j in d:
            if d[j]==1:
                return j

    #变态方法
    '''
    算法：set返回一个无重复项的数组，求和乘二，减去原数组，得到的就是单独元素。
    可行性：除了某个元素只出现一次以外，其余"每个元素均出现两次"。
    缺点：
    '''
    def singleNumber3(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(list(set(nums)))*2 - sum(nums)

sol = Solution()
print(sol.singleNumber1([1,2,3]))