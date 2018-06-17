'''
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
'''

#me 144ms
class Solution:
    def singleNumber(self, nums):
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
def singleNumber(self, nums):
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
def singleNumber(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    return sum(list(set(nums)))*2 - sum(nums)