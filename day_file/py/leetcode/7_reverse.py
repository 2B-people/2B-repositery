'''
问题：
定一个 32 位有符号整数，将整数中的数字进行反转。
示例 1:                                     示例 2:
输入: 123                                      输入: -123
输出: 321                                      输出: -321
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

解决方案：
方法：弹出和推入数字 & 溢出前进行检查
思路：我们可以一次构建反转整数的一位数字。在这样做的时候，我们可以预先检查向原整数附加另一位数字是否会导致溢出。
算法：反转整数的方法可以与反转字符串进行类比。我们想重复“弹出” 。
要在没有辅助堆栈 / 数组的帮助下 “弹出” 和 “推入” 数字，我们可以使用数学方法。
事先检查这个语句是否会导致溢出很容易
    if (rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
    if (rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
    rev = rev * 10 + pop;
'''

class Solution:
    # 方法1，转字符串再颠倒
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        a = str(x)
        if x>=0:
            a = self.reverseString1(a)
            x = int(a)
        else:
            a = a[1:]
            a = self.reverseString1(a)
            x = -int(a)
        if x >2**31-1 or x <-2**31:
            return 0
        else:
            return x
    def reverseString1(self, s):
        """
        :type s: str
        :rtype: str
        """
        return(s[::-1])


    # 方法2，数值运算，数值弹出推入
    def reverse1(self, x):
        rev = 0
        sign = 1
        if x < 0:
            sign = -1
            x *= -1
        while (x != 0):  
            temp = rev
            rev = temp*10 + x % 10
            x //= 10
            
        if sign == -1:
            rev *= -1
        if rev > 0x7fffffff or rev < -0x80000000:
            return 0
        else:
            return rev

if __name__ =='__main__':
    sol = Solution()
    print(sol.reverse(-98765))