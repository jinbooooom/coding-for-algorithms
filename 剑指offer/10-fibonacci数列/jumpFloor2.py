# -*- coding:utf-8 -*-
"""
题目：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
"""

class Solution:
    def jumpFloorII(self, number):
        """
        提示：
        设 n 级台阶有 f(n) 中跳法，青蛙最后一次跳，有 n 种跳法：
            若最后一次跳只跳 1 个台阶则前面的 n-1 级有 f(n-1) 种方法
            若最后一次跳只跳 2 个台阶则前面的 n-2 级有 f(n-2) 种方法
            ...
            若最后一次跳只跳 n-1 个台阶则前面的 1 级有 f(1) 种方法
            若最后一次跳只跳 n 个台阶只有 1 种方法，（一步直接跳上来)
        所以 f(n) = f(n-1) + f(n-2) + ... + f(1) + 1   (1)
        把 n - 1 代入上式 n 中得：
        f(n-1) = f(n-2) + f(n-3) + ... + f(1) + 1   (2)
        (1) - (2) 可得 f(n) = 2f(n-1)，这是个等比数列。
        但写程序直接按照（1）式来写就好了。
        """
        # write code here

        f = [0, 1, 2]
        if number in f:  # 当 number 处于闭区间 [0, 2]时，恰有f[number] = number
            return number

        for i in range(3, number + 1):
            f.append(sum(f) + 1)
            # f[i] = f[0] + f[1] + ... + f[i-1] + 1 = sum(f) + 1
            # 加 1 是因为青蛙可以一次跳 i 级台阶。
        return f[-1]

