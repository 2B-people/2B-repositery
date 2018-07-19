function x = freebody(x0,v0,t)
% calculation of free falling
% x0: initial displacement in m 
% v0: initial velocity in m/sec 
% t: the elapsed time in sec
% x: the depth of falling in m
x = x0+v0.*t +1/2*9.8*t.*t;