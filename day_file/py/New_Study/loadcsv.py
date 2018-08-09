#!/usr/bin/python3
# -*- coding:utf-8 -*-


import csv
import numpy as np
from coding_analyze import Timer
def loadCSVfile1():
    with open("ocean.csv", "r", encoding = "utf-8") as f:
        reader = csv.reader(f)
        column = [row for row in reader]

    column.pop(0)
    matrix = np.zeros((len(column),len(column[1])))
    for i in range(len(column)):
        for j in range(len(column[1])):
            matrix[i][j] = int(column[i][j])
    # print(matrix)
    return matrix

# or
def loadCSVfile2():
    tmp = np.loadtxt("ocean.csv",dtype=np.str,delimiter=",")
    data = tmp[1:,0:].astype(np.int)
    return data
with Timer() as t:
    mat = loadCSVfile2()
    print(mat)