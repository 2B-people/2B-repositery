import turtle
import time
turtle.pensize(2)
turtle.bgcolor("black")
colors =["red","yellow","purple","blue"]
turtle.tracer(False)
for i in range(400):
    turtle.forward(2*i)
    turtle.color(colors[i % 4])
    turtle.left(91)
turtle.tracet(True)

