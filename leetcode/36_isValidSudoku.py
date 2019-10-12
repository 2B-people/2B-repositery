'''
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
上图是一个部分填充的有效的数独。
数独部分空格内已填入了数字，空白格用 '.' 表示。
示例 1:
输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
示例 2:
输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:
一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。
'''


class Solution:
    def __containsDuplicate(self,nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()
        num =[]
        for i in range(len(nums)):
            if nums[i] != '.':
                num.append(nums[i])
        if len(num)==1:
            return False
        for i in range(len(num)):
            if num[i-1] == num[i]:
                return True
        return False
    # 88ms，my 
    # TODO add解决方案   
    def isValidSudoku1(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        nums = []
        matrix = []
        for row in board:
            nums = row.copy()
            if self.__containsDuplicate(nums):
                return False
        for i in range(9):
            col = [board[j][i] for j in range(9)]
            if self.__containsDuplicate(col):
                return False
        for i in range(0,9,3):
            for j in range(i,i+3):
                matrix.extend([board[0][j],board[1][j],board[2][j]])
            if self.__containsDuplicate(matrix):
                return False
            matrix.clear()
        for i in range(0,9,3):
            for j in range(i,i+3):
                matrix.extend([board[3][j],board[4][j],board[5][j]])
            if self.__containsDuplicate(matrix):
                return False
            matrix.clear()
        for i in range(0,9,3):
            for j in range(i,i+3):
                matrix.extend([board[6][j],board[7][j],board[8][j]])
            if self.__containsDuplicate(matrix):
                return False
            matrix.clear()
        return True

    # 77ms
    #TODO add解决方案
    def isValidSudoku2(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        Cell = [[] for i in range(9)]                   # 没有必要用dict,我们只某个数字关心有没有出现过
        Col =  [[] for i in range(9)]
        Row =  [[] for i in range(9)]

        for i,row in enumerate(board):                  # 将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中
            for j,num in enumerate(row):
                if num != '.':
                    k = (i//3)*3 + j//3
                    if num in Row[i] + Col[j] + Cell[k]:    # list的骚操作,将三个list顺序的拼接 
                        return False
                    Row[i].append(num)
                    Col[j].append(num)
                    Cell[k].append(num)

        return True

sol = Solution()
board = [
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
print(sol.isValidSudoku1(board))

