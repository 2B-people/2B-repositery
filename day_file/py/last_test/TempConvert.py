# TempConvert.py

    val=input("请输入温度及单位")     #输入变量及提示语
    if val[-1] in ['c','C']:         #if判断语句，val[-1]指从最后的第一个
        sub=1.8*float(val[0:-1])+32  #val指0到-1之间的元素
        print("转换的温度为H%f"%sub)  #print有待研究
    elif val[-1] in ['F','f']:
        aub=(float(val[0:-1-32]))/1.8
        print("转换的温度为F%f"%aub)
    else:
        print("输入错误")

