import time
import webbrowser

t_break = 3
break_count = 0

print("this program started on"+time.ctime())
while(break_count<t_break):
    time.sleep(2*60*60)
    webbrowser.open("https://zhuanlan.zhihu.com/machine-learning-book")
    break_count += 1