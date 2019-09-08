# -*- coding:itf-8 -*-
"""
https://leetcode-cn.com/problems/valid-perfect-square

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：完全平方数即该数字能够分解为两个正整数的平方。不要使用任何内置的库函数，如  sqrt。

示例 1：
输入：16
输出：True

示例 2：
输入：14
输出：False

"""


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 1
        right = num
        while left <= right:
            mid = (left + right)//2
            t = mid ** 2
            if t > num:
                right = mid - 1
            elif t < num:
                left = mid + 1
            else:
                return True
        return False