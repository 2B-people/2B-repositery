#DrawSnake.py

import turtle        #调用库，有点像c的头文件

def drawSnake(rad, angle, len , neckrad):   #函数code
	for i in range(len):                    #for循环控制节数
		turtle.circle(rad, angle)           #轨迹为圆，rad为半径，（正代表圆心在左，angle为弧度值
		turtle.circle(-rad, angle)
	turtle.circle(rad, angle/2)
	turtle.fd(rad)                          #直线段
	turtle.circle(neckrad+1, 180)
	turtle.fd(rad*2/3)
	
def main():                              #优先运行,init进行
	turtle.setup(1300, 800, 0, 0)        #启动图形窗口（width，height，startx，starty）
	pythonsize = 30                      
	turtle.pensize(pythonsize)           #运动轨迹宽度
	turtle.pencolor("red")               #运动轨迹颜色
	turtle.seth(-40)                     #启动时方向
	drawSnake(40,80,5,pythonsize/2)
	
main()
