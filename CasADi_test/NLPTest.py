#!/usr/bin/env python
# -*- coding: utf-8 -*-

from casadi import *
import time


# Symbols/expressions
x = MX.sym('x')
y = MX.sym('y')
z = MX.sym('z')
f = x**2+100*z**2
g = z+(1-x)**2-y

nlp = {}                 # NLP declaration
nlp['x']= vertcat(x,y,z) # decision vars
nlp['f'] = f             # objective
nlp['g'] = g             # constraints

# Create solver instance
F = nlpsol('F','ipopt',nlp);


# Solve the problem using a guess
start_time = time.time()
F(x0=[2.5,3.0,0.75],ubg=0,lbg=0)

end_time = time.time()
elapsed_time = (end_time - start_time)*1000
print(f"Elapsed time: {elapsed_time:.2f} ms")
