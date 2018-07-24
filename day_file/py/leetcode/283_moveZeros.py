'''
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
'''

class Solution:
    # 1000ms ,时间太长
    '''
    算法：利用两个索引，curindox向前移动，与lastindox计算差值前移
    '''
    def moveZeroes1(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        curindox = lastindox = len(nums)-1
        while curindox>=0:
            if(nums[curindox] == 0):
                count = lastindox - curindox
                for i in range(count):
                    nums[curindox+i] = nums[curindox+i+1]
                nums[lastindox] = 0
                lastindox -= 1
            curindox -= 1

    #60ms
    '''
    TODO add 算法记录
    算法：
    '''
    def moveZeroes2(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j], nums[i] = nums[i], nums[j]
                j += 1
sol = Solution()
nums = [0,0,1]
sol.moveZeroes2(nums)
print(nums)


