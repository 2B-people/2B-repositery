import os
import time
import sys

baseroot = os.getcwd()
whiteDict = {'py':['py'],'cpp/c':['cpp','h','c'],'web':['html','css','ts'],'matlab':['m']}
FileList = []

def afileline(f_path):
    count = 0
    for file_line in open(f_path,'rb').readlines():
        if file_line != '' and file_line != '\n': #过滤掉空行
            count += 1
    return count

def Readfile(t_coding):
    for root,dirs,files in os.walk(baseroot):
        for t_file in files:
            ext = t_file.split('.')[-1]
            if ext in whiteDict[t_coding]:
                FileList.append(root+os.sep+t_file)

def len(t_coding):
    s_time = time.clock()
    Readfile(t_coding)
    sum = 0
    for file in FileList:
        sum += afileline(file)
    print('program line sum is:',sum)    
    print('Done! Cost time is ',(time.clock()-s_time),'second') 