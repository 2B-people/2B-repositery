'''
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
输入描述:
输入数据有多组，每组占一行，由两个整数n（n < 10000）和m(m < 1000)组成，
n和m的含义如前所述。
输出描述:
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。
'''
import sys
import math

for line in sys.stdin:
    str1 = line.split(' ')
    init = int(str1[0])
    i = int(str1[1]) - 1
    lst = [init]
    while i > 0:
        lst.insert(0, math.sqrt(lst[0]))
        i -= 1
    result = 0
    for value in lst:
        result += value
    print('%.2f' % result)
