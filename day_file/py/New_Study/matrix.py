# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import random

def random_int_list(start, stop, length):
    start, stop = (int(start), int(stop)) if start <= stop else (int(stop), int(start))
    length = int(abs(length)) if length else 0
    random_list = []
    for i in range(length):
        random_list.append(random.randint(start, stop))
    return random_list

data = random_int_list(10,99,25)

matrix = [[0 for i in range(5)]for i in range(5)]
matrix[0] = data[:5]
matrix[1] = data[5:10]
matrix[2] = data[10:15]
matrix[3] = data[15:20]
matrix[4] = data[20:25]
 
data.sort()

for i in range(5):
    for j in range(5):
        if matrix[i][j] == data[24]:
            matrix[i][j] = matrix[2][2]

for i in range(5):
    for j in range(5):
        if matrix[i][j] == data[0]:
            matrix[i][j] = matrix[0][0]
            
for i in range(5):
    for j in range(5):
        if matrix[i][j] == data[1]:
            matrix[i][j] = matrix[0][4]
            
for i in range(5):
    for j in range(5):
        if matrix[i][j] == data[2]:
            matrix[i][j] = matrix[4][0]
            
for i in range(5):
    for j in range(5):
        if matrix[i][j] == data[3]:
            matrix[i][j] = matrix[4][4]

matrix[2][2] = data[24]
matrix[0][0] = data[0]
matrix[0][4] = data[1]
matrix[4][0] = data[2]
matrix[4][4] = data[3]

print (matrix[0])
print (matrix[1])
print (matrix[2])
print (matrix[3])
print (matrix[4])

