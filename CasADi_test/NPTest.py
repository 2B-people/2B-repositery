#!/usr/bin/env python
# -*- coding: utf-8 -*-

import casadi as ca

if __name__ == '__main__':
    print("begin the test program.")
    x = ca.SX.sym('x')
    y = ca.SX.sym('y')

    f = x**2 + y**2
    g = x+y-10

    qp = {'x': ca.vertcat(x, y), 'f': f, 'g': g}
    Solve = ca.qpsol('Solve', 'osqp', qp)
    # print(Solve)
    # r = Solve(lbg = 0)

    # x_opt = r['x']
    # print('x_opt = ',x_opt)
    A = ca.SX.sym('A', 3, 2)
    x = ca.SX.sym('x', 2)
    print(ca.jacobian(A@x, x))
