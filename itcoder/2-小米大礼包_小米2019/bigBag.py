# -*- coding:utf-8 -*-
"""

小米之家是成人糖果店。里面有很多便宜，好用，好玩的产品。
中秋节快到了，小米之家想给米粉们准备一些固定金额大礼包。
对于给定的一个金额，需要判断能不能用不同种产品（一种产品在礼包最多出现一次）组合出来这个金额。
聪明的你来帮帮米家的小伙伴吧。

输入描述:
输入 N （N 是正整数， N  <= 200）
输入 N 个价格p（正整数, p <= 10000）用单空格分割
输入金额 M（M是正整数，M <= 100000 ）

输出描述:
能组合出来输出 1
否则输出 0

输入例子1:
6
99 199 1999 10000 39 1499
10238

输出例子1:
1

"""
class Solution:
    def main1(self, prices, M, N):
        """
        优化的一维动态规划
        
        :param prices: list of prices
        :param M: target money
        :return: 
        """
        dp = [1] + [0 for _ in range(M)]
        dp[0] = 1
        for i in range(N):
            for j in range(M, prices[i] - 1, -1):
                dp[j] += dp[j - prices[i]]
                if dp[j]:
                    return 1
        return 0

    def main2(self, prices, M, N):
        """
        二维动态规划

        """
        dp = [[0 for _ in range(M+1)] for _ in range(N+1)]
        dp[0][0] = 1
        for i in range(N):
            for j in range(M, prices[i] - 1, -1):
                dp[i][j] += dp[i][j - prices[i]]
                if dp[i][j]:
                    return 1
        return 0


if __name__ == "__main__":
    # 这道题目里的 self.main1() 与 self.main2() 在牛客网测试均超时，
    # 思路没有问题，但复杂度太高。

    N = int(input().strip())
    prices = list(map(int, input().strip().split()))
    M = int(input().strip())
    
    f = Solution()
    print(f.main2(prices, M, N))
