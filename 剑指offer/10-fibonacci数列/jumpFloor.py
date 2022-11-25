# -*- coding:utf-8 -*-
"""
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
"""


class Solution:
    def jumpFloor(self, n):
        """
        提示：
        设 n 级台阶有 f(n) 种跳法，青蛙最后一次跳，有两种跳法：
            若最后一次跳只跳一个台阶则前面的 n-1 级有 f(n-1) 种方法
            若最后一次跳只跳两个台阶则前面的 n-2 级有 f(n-2) 种方法
        """
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

