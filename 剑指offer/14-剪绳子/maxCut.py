# -*- coding:utf-8 -*-
"""
把长度为 n 的绳子剪成 m 段，m, n 均为整数（可以剪零刀），问 m 小段绳子长度之积最大为多少？
比如：
长度为 8 的绳子可以剪成 3，3，2 三段，其积最大为 18。
长度为 3 的绳子不剪，其积最大为 3。
"""


class Solution:

    def __init__(self):
        self.product = {0: 0, 1: 1, 2: 2, 3: 3}  # 长度为 key 的子绳最优解为 value

    def maxCut1(self, length):  # 动态规划解答
        if length < 0:
            return 0
        elif length < 4:
            return self.product[length]

        for i in range(4, length + 1):
            maxProduct = 0
            for j in range(1, i//2 + 1):
            # for j in range(1, i - 1 + 1):
                # 对于一段长度为 i 的绳子，第一刀剪 j 长度，则 f(i) = max(f(j) * f(i-j))，
                # 和第一刀剪 i-j 长度，本质上是一样的，故循环条件是 range(1, i//2 + 1)
                tmpProduct = self.product[j] * self.product[i - j]
                if maxProduct < tmpProduct:
                    maxProduct = tmpProduct
            self.product[i] = maxProduct
        return self.product[length]

    def maxCut2(self, length):  # 贪心算法求解
        if length < 0:
            return 0
        elif length < 5:
            return length
        else:
        # 当 length >= 5 时，尽量裁剪成长度为 3 的小绳子
            return 3 * self.maxCut2(length - 3)



if __name__ == "__main__":
    f = Solution()
    length = 8
    print("动态规划求解：")
    print(f.maxCut1(length))
    print(f.product)
    print("贪心算法求解：")
    print(f.maxCut2(length))