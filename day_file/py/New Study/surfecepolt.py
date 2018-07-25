import numpy as np
from matplotlib import pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D

u = np.linspace(-1,1,100)
x,y = np.meshgrid(u,u)     # 网格坐标生成函数
z = x**2+y**2
 
fig = plt.figure()
ax = Axes3D(fig)
# cmap = color_map,另外两个参数是瓦片步长
ax.plot_surface(x,y,z,rstride=4,cstride=4,cmap='rainbow')
plt.show()