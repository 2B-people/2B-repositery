'''
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
'''

class Solution:
    #1448ms
    '''
    算法：暴力法，遍历列表，找到是否有一个等于target-x相同的目标元素
    复杂度分析：时间复杂度：O(N^2)      空间复杂度：O(1)
    '''
    def twoSum1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            sum_tor = target - nums[i]
            if sum_tor in nums:
                if i != nums.index(sum_tor):
                    return [i,nums.index(sum_tor)]

    # 52ms
    '''
    算法：一遍哈希表，在进行迭代并将元素插入到表中的同时，
    我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。
    如果它存在，那我们已经找到了对应解，并立即将其返回。
    复杂度分析：时间复杂度 O(n)    空间复杂度 O(n)
    '''            
    def twoSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic={}
        for i in range(len(nums)):
            if nums[i] in dic:              #查找
                return [dic[nums[i]],i]
            else:
                dic[target-nums[i]] = i     #插表

sol = Solution()
print(sol.twoSum2([3,2,4],6))