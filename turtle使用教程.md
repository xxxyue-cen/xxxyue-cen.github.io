# turtle 库

## 1、 安装
pip install turtle

## 2、使用turtle库
```python
import turtle
```

## 3、turtle方法

* setup 设置窗口大小及位置
setup（width,height,startx,starty）

* 色彩模式 
colornode(mode)
mode  1-0  RGB小数值模式   255 RGB整数值模式

* 抬起笔
penup()

* 落下笔
pendown()

* 画笔宽度
pensize(width)

* 画笔颜色
pencolor(color)
pencolor("red")   颜色字符串
pencolor(0.23,0.34,0.34)     RGB小数值
pencolor((0,23,0.34,0.45))   RGB元组


* 运动控制函数

* 将画笔移动到坐标（x，y）的位置
goto( x , y )
goto( 100 , 100 )

* 向前进d，d可以为负数
forward(d)
fd(d)

* 向后行进d，d可以为负数
backword(d)
bk(d)

* 根据半径以及边画多边形
circle(r,steps = None)   圆
circle(r,steps = 3)  三角形
circle(r,steps = 4) 正方形
circle(r,180)   半圆  180为角度

* 方向控制函数
seth()  改变方向  只改变方向不行进
angle 为绝对度数
seth(angle)
seth(90)
seth(-135)

* 右转
right(angle)
right(90)

* 左转
left(angle)
left(90)

* 停止绘制
done()


* 绘制图形的填充颜色
fillcolor(color)

* 开始填充
begin_fill()

* 结束填充
  end_fill()

  

* 全局控制

* 清除窗口
  clear()

* 重置窗口
reset()

* 撤销上一次操作
  undo()

* 复制当前图形
stamp()

* 风车 
```python
import turtle
turtle.setup(650,650)

turtle.penup()
turtle.pensize(3)
turtle.pencolor("red")
turtle.pendown()
for x in [0,90,180,270]:
    turtle.seth(x)
    turtle.fd(100)
    turtle.seth(x + 90)
    turtle.circle(100,-45)
    turtle.goto(0,0)

turtle.done()
```
* 五角星
```python
import  turtle
import  time

turtle.pensize(5)
turtle.pencolor("yellow")
turtle.fillcolor("red")

turtle.begin_fill()
for _ in range(50):
    turtle.forward(200)
    turtle.right(144)
turtle.end_fill()
time.sleep(2)

turtle.penup()
turtle.goto(-150,-120)
turtle.color("violet")
turtle.write("DOne",font = ("Arial",40,"normal"))

turtle.mainloop()
```

* 动态时钟
```python
import turtle
from datetime import *


# 抬起画笔，向前运动一段距离放下
def Skip(step):
    turtle.penup()
    turtle.forward(step)
    turtle.pendown()


def mkHand(name, length):
    # 注册Turtle形状，建立表针Turtle
    turtle.reset()
    Skip(-length * 0.1)
    # 开始记录多边形的顶点。当前的乌龟位置是多边形的第一个顶点。
    turtle.begin_poly()
    turtle.forward(length * 1.1)
    # 停止记录多边形的顶点。当前的乌龟位置是多边形的最后一个顶点。将与第一个顶点相连。
    turtle.end_poly()
    # 返回最后记录的多边形。
    handForm = turtle.get_poly()
    turtle.register_shape(name, handForm)


def Init():
    global secHand, minHand, hurHand, printer
    # 重置Turtle指向北
    turtle.mode("logo")
    # 建立三个表针Turtle并初始化
    mkHand("secHand", 135)
    mkHand("minHand", 125)
    mkHand("hurHand", 90)
    secHand = turtle.Turtle()
    secHand.shape("secHand")
    minHand = turtle.Turtle()
    minHand.shape("minHand")
    hurHand = turtle.Turtle()
    hurHand.shape("hurHand")

    for hand in secHand, minHand, hurHand:
        hand.shapesize(1, 1, 3)
        hand.speed(0)

    # 建立输出文字Turtle
    printer = turtle.Turtle()
    # 隐藏画笔的turtle形状
    printer.hideturtle()
    printer.penup()


def SetupClock(radius):
    # 建立表的外框
    turtle.reset()
    turtle.pensize(7)
    for i in range(60):
        Skip(radius)
        if i % 5 == 0:
            turtle.forward(20)
            Skip(-radius - 20)

            Skip(radius + 20)
            if i == 0:
                turtle.write(int(12), align="center", font=("Courier", 14, "bold"))
            elif i == 30:
                Skip(25)
                turtle.write(int(i / 5), align="center", font=("Courier", 14, "bold"))
                Skip(-25)
            elif (i == 25 or i == 35):
                Skip(20)
                turtle.write(int(i / 5), align="center", font=("Courier", 14, "bold"))
                Skip(-20)
            else:
                turtle.write(int(i / 5), align="center", font=("Courier", 14, "bold"))
            Skip(-radius - 20)
        else:
            turtle.dot(5)
            Skip(-radius)
        turtle.right(6)


def Week(t):
    week = ["星期一", "星期二", "星期三",
            "星期四", "星期五", "星期六", "星期日"]
    return week[t.weekday()]


def Date(t):
    y = t.year
    m = t.month
    d = t.day
    return "%s %d%d" % (y, m, d)


def Tick():
    # 绘制表针的动态显示
    t = datetime.today()
    second = t.second + t.microsecond * 0.000001
    minute = t.minute + second / 60.0
    hour = t.hour + minute / 60.0
    secHand.setheading(6 * second)
    minHand.setheading(6 * minute)
    hurHand.setheading(30 * hour)

    turtle.tracer(False)
    printer.forward(65)
    printer.write(Week(t), align="center",
                  font=("Courier", 14, "bold"))
    printer.back(130)
    printer.write(Date(t), align="center",
                  font=("Courier", 14, "bold"))
    printer.home()
    turtle.tracer(True)

    # 100ms后继续调用tick
    turtle.ontimer(Tick, 100)


def main():
    # 打开/关闭龟动画，并为更新图纸设置延迟。
    turtle.tracer(False)
    Init()
    SetupClock(160)
    turtle.tracer(True)
    Tick()
    turtle.mainloop()


if __name__ == "__main__":
    main()

```














