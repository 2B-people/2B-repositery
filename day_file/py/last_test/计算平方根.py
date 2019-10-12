#计算平方根的两种方法：一个是2分法；一个是牛顿拉复生法

def sguareBootBi(x,epsilon):
    assert x >= 0 #x must be positive
    assert epsilon > 0 #epsilon must be positive

    low = 0
    high = max(x,1.0)
    guess = (low +high)/2.0
    ctr = 1


    while abs(guess ** 2 -x) > epsilon and ctr <= 100:
        #print('low:',low,'high:',high,'guess',guess)
        if guess**2 < x:
            low = guess
        else:
            high = guess
        guess = (low+high)/2.0
        ctr += 1
    
    assert ctr <= 100
    print('time of iteration:',ctr,'sqrt',guess)
    return guess

def squarRootNR(x, epsilon):
    assert x >= 0
    assert epsilon >= 0

    x = float(x)
    guess = x/2.0
    #guess = 0.001
    diff = guess**2 - x
    ctr = 1
    while abs(diff) > epsilon    and ctr <= 100:
        guess = guess - diff/(2.0*guess)
        diff = guess**2 - x
        ctr += 1
    assert ctr <=100
    print('NR method, Num,iteration:',ctr)
    return guess


x = float(input('x:'))
epsilon = float(input('epsilon:'))
print(sguareBootBi(x,epsilon))
print(squarRootNR(x,epsilon))