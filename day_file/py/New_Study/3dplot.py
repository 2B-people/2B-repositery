import numpy as np 
from matplotlib import pyplot as plt 
from matplotlib import animation#动态图所需要的包

fig,ax = plt.subplots()#子图像
x = np.arange(0,2*np.pi,0.01)
line, = ax.plot(x,np.sin(x))

def animate(i):
    line.set_ydata(np.sin(x+i/10))#用来改变的y对应的值
    return line,
def init():
    line.set_ydata(np.sin(x))#动态图初始图像
    return line,

ani = animation.FuncAnimation(fig=fig,func=animate,init_func=init,interval=20)#动态作图的方法，func动态图函数，init_func初始化函数，interval指图像改变的时间间隔
plt.show()