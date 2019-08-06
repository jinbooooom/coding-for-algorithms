# -*- coding:utf-8 -*-
"""
大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
"""


class Solution:
    def Fibonacci1(self, n):
        # write code here

        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        if n > 2:
            return self.Fibonacci1(n-1) + self.Fibonacci1(n-2)

    def Fibonacci2(self, n):
        # write code here

        f0 = 0
        f1 = 1
        f2 = 0
        if n == 0:
            return f0
        elif n == 1:
            return f1
        else:
            for i in range(2, n + 1):
                f2 = f1 + f0
                f1, f0 = f2, f1
            return f2


s = Solution()
l = []
for i in range(9):
    l.append(s.Fibonacci2(i))
print(l)