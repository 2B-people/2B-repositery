'''
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
'''

class Solution(object):
    '''
    算法：python的数组操作。#list.pop()移除列表中的一个元素（默认最后一个元素），并且返回该元素的值
        #list[].insert()将对象插入列表.
    缺点：属于python的高级用法，并不是一种很好的算法，时间复杂度空间复杂度完全依赖语言本身。
    '''
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(k):
            nums.insert(0,nums.pop())