'''
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
'''
# TODO 翻转矩阵解决方案
from coding_analyze import Timer

class Solution:
    # 72ms，mine
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        # 根据对角线，找对应位置，互换两个数字的值。
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
        
        # 对每一行数字，根据中线左右翻转。
        for i in range(n):
            for j in range(n//2):
                matrix[i][j],matrix[i][n-j-1] = matrix[i][n-j-1],matrix[i][j]
        # or
        # for i in range(length):
        #     matrix[i] = matrix[i][::-1]

    #40ms
    def rotate2(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if matrix == None or len(matrix) <= 1:
            return
        
        def swap(i, j, x, y):
            temp = matrix[i][j]
            matrix[i][j] = matrix[x][y]
            matrix[x][y] = temp
            
        n = len(matrix)
        for i in range(0, n):
            for j in range(i, n-i-1):
                swap(i,j, n-j-1, i)
                swap(n-j-1, i, j, n-i-1)
                swap(n-j-1, i, n-i-1, n-j-1)

if __name__== '__main__':
    with Timer() as t:   
        sol = Solution()
        matrix = [
        [ 5, 1, 9,11],
        [ 2, 4, 8,10],
        [13, 3, 6, 7],
        [15,14,12,16]
        ]
        for i in range(len(matrix)):
            print(matrix[i])
        print('than:')
        sol.rotate(matrix)
        for i in range(len(matrix)):
            print(matrix[i])
