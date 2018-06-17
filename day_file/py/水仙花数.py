import sys

a = [153,370,371,407]
for i in sys.stdin.readlines():
    a0,a1=map(int, i.strip().split())
    res = []
    for j in range(a0,a1 + 1):
        if j in a: res.append(j)

    print("no"if not res else " ".join(map(str,res)))