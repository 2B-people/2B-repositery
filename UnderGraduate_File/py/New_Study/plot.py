import numpy as np 
from matplotlib import pyplot as plt 

x = np.arange(-10,10,0.001)
y =  x**2
plt.title("Matplotlib demo") 
plt.xlabel("x axis caption") 
plt.ylabel("y axis caption") 
plt.plot(x,y) 
plt.show()