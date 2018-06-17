import sys
import math
def sqlrt(n, m):
    sum = 0
    while m > 0:
        m -= 1
        sum += n
        n = math.sqrt(n)
    return "{0:.2f}".format(sum)
a = sys.stdin.readlines()
for i in a:
    n = int(i.split(" ")[0])
    m = int(i.split(" ")[1])
    print(sqlrt(n, m))
