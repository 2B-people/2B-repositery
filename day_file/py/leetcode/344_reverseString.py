'''
请编写一个函数，其功能是将输入的字符串反转过来。
示例：
输入：s = "hello"
返回："olleh"
'''

# 注意字符串的处理，没有啥算法好说的
# 注意空间复杂度，不需要重新分配内存
class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        a = list(s)
        i = 0
        j = len(a)-1
        while i<j:
            a[i],a[j] = a[j],a[i]
            i += 1
            j -= 1
        # a = str(a)
        s = ''.join(a)
    
    # 骚年，渴望力量吗？，我用python
    def reverseString1(self, s):
        """
        :type s: str
        :rtype: str
        """
        return(s[::-1])

if __name__=='__main__':
    sol = Solution()
    s = 'hello'
    sol.reverseString(s)
    print(s)