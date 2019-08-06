# -*- coding:utf-8 -*-
"""
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
"""


class Solution:
    def rectCover(self, number):
        """
        最后一次覆盖是竖着覆盖则前面的2*(n-1)矩形有f(n-1)种方法，
        最后一次覆盖是横着覆盖则前面的2*(n-2)矩形有f(n-2)种方法
        """
        # write code here

        f0 = 0
        f1 = 1
        f2 = 2
        if number == 0:
            return f0
        elif number == 1:
            return f1
        elif number == 2:
            return f2
        else:
            for i in range(3, number + 1):
                f3 = f2 + f1
                f2, f1 = f3, f2
            return f3