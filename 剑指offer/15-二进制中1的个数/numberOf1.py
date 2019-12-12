# -*- coding:utf-8 -*-
"""
输入一个整数，输出该数二进制表示中 1 的个数。其中负数用补码表示。
有必要了解，对负数，右移左边补 1
对正数右移，左边补零
"""


class Solution:
    def NumberOf1(self, n):
        """
        将 n 与 1 作与运算，统计结果是否为 1，然后再右移 n，
        但这样有一个 bug，对于负数，符号位是 1，右移会导致结果变成 0xFFFFFFFF，陷入死循环，
        或者像 python 实现一样，限制移位操作次数，
        或者考虑不右移 n，而是左移 1 再与 n与。
        """
        # write code here

        return sum([(n >> i & 1) for i in range(32)])
        """
        对负数会引起死循环
        count = 0
        while n:
            count += (n & 1)
            n = n>>1
        return count
        """

if __name__ == "__main__":
    f = Solution()
    print(f.NumberOf1(-11))