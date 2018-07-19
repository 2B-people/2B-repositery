function [f a] = acc(v1,v2,t1,t2,m);
a = (v1-v2)/(t1-t2);
f = a.*m;