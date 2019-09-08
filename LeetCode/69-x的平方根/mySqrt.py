# -*- coding:itf-8 -*-
"""
https://leetcode-cn.com/problems/sqrtx/

实现 int sqrt(intx) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例
输入: 4
输出: 2

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
"""

class Solution(object):
    def mySqrt(self, x):
        """
        提示：
        二分查找
        """
        if x < 2:
            return x

        left, right = 1, x // 2
        while left <= right:
            mid = (left + right) // 2
            if mid * mid > x:
                right = mid - 1
            else:
                left = mid + 1
        return left - 1
