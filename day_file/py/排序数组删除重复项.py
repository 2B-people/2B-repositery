'''
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
示例 1:
给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
'''

# me 
'''
算法：python一大强大之处，对列表操作可以单独删除其中元素，不必考虑是否会空
    给定的数组是排序数组；
    循环数组，找到下一个元素A[i+1]等于A[i]，就删除A[i+1]，
    注意的是循环次数需要 -1，避免索引超限。
 
    允许重复一次，则直接检查元素A[i+2]是否等于A[i]即可，
    因为如果A[i+2]等于A[i]，那么A[i+1]也等于A[i]，
    此时删除A[i+2]即可。
    当然，循环次数需要 -2
'''
class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        while i < len(nums)-1:
            if(nums[i]==nums[i+1]):
                nums.remove(nums[i])
            else:
                i += 1
        return len(nums)

    def removeDuplicates2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        while i < len(nums)-2:
            if(nums[i]==nums[i+2]):
                nums.remove(nums[i])
            else:
                i += 1
        return len(nums)


#最快60ms
'''
算法：set()创建一个无序不重复元素集，及删除重复项，再排序返回给原数组；
'''
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums[:] = sorted(list(set(nums)))
        return len(set(nums))
