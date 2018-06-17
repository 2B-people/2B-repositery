#一、python对象的"==、is"比较
"""
1、python的比较总是检查复合对象的所有部分，直到可以得出结果为止。
2、会自动遍历嵌套的所有数据结构，有多深走多深，首次发现的差值将决定比较的结果
"""

"""
== :操作符测试值的相等性
is :表达式测试对象的一致性，表示同一个对象，在同一内存地址中
输出结果：
True False
"""
L1 = [1,('A',2)]
L2 = [1,('A',2)]
print L1 == L2,L1 is L2

"""
关于短字符串的一致性比较特殊：
python内部暂时储存并重复使用短字符串作为最佳化，实际内存中只有一个字符串'spam‘供S1、S2分享
输出结果：
True True
"""


S1 = "SPAM"
S2 = "SPAM"
print S1 == S2,S1 is S2

"""
当比较的字符串较长时 is比较结果为False
运行结果：False
"""
S11 = "a longer strnig"
S22 = "a longer string"
print S11 is S22

"""
列表、字典、元组、自定义程序类型的一致性判定（is）
以下判定结果均为False,因为都不是一个对象，内存地址不一样
"""
l = [1,3,'a']
print l is list

d = {1:1,'a':'b'}
print d is dict

t = (1,2,3)
print t is tuple

class A(object):
    def __init__(self):
        print "object is born!"

a = A()
print a is A
print '---------------'

a1 = 1
a2 = 1
print a1 is a2 #返回True

#二、python对象的大小比较规则：
"""
1、数字通过相对大小进行比较
2、字符串按照字典顺序（编码顺序）,一个字符接一个字符进行比较
3、列表和元组从左到右对每部分的内容进行比较
4、字典通过排序后的(键,值)列表进行比较，pyton3.0中不支持
5、数字混合类型pyton3.0中不支持，拼音。6中允许
"""

#运行结果：[True, True, True, True]
print [33 < 99,'abc' < 'ac',{'a':1,'b':2} > {'a':1,'B':2},1 < 'spam']

#嵌套比较
"""
运行结果：False False True
"""
Li1 = [1,('a',3)]
Li2 = [1,('a',2)]
print Li1 < Li2,Li1 == Li2,Li1 > Li2