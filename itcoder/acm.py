#!/usr/bin/env python
# coding=utf-8
# Python使用的是3.4.3，缩进可以使用tab、4个空格或2个空格，但是只能任选其中一种，不能多种混用
while 1:
    a = []
    s = input()

    if s != "":
        for x in s.split():
            a.append(int(x))

        print(sum(a))
    else:
        break