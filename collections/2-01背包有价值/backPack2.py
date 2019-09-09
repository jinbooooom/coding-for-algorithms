# -*- coding:utf-8 -*-
"""
https://www.lintcode.com/problem/backpack-ii/description

有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
装入背包的物品总价值最大是多大?

样例 1:
输入: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
输出: 9
解释: 装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

样例 2:
输入: m = 10, A = [2, 3, 8], V = [2, 5, 8]
输出: 10
解释: 装入 A[0] 和 A[2] 可以得到最大价值, V[0] + V[2] = 10

注意事项
    A[i], V[i], n, m 均为整数
    你不能将物品进行切分
    你所挑选的要装入背包的物品的总大小不能超过 m
    每个物品只能取一次

"""

class Solution:
    """
    @param m: An integer m denotes the n of a backpack
    @param A: Given n items with n A[i]
    @param V: Given n items with value V[i]
    @return: The maximum value
    """
    def backPackII(self, m, A, V):
        """
        提示：
        dp[i][j]：前 i 个物品放入容量为 j 的背包的最大价值；
        dp[i-1][j-A_i] + V_i：放入第 i 个物品时的价值；
        dp[i-1][j]：不放第 i 个物品时的价值；

        在遇到第 i 个物品时，需要考虑该物品是放入还是不放入
        状态转移方程为：
        dp[i][j] = max(dp[i-1][j-A_i] + V_i, dp[i-1][j])

        第一层循环 i：0~n
        第二层循环 j：m ~ Ai，倒序是因为每个物品只能用一次。
        可简化成一维数组。
        dp[j] = max(dp[j - A[i]] + V[i], dp[j])

        """
        # write your code here
        n = len(A)
        if m <= 0 or n <= 0:
            return 0
        dp = [0 for _ in range(m + 1)]
        for i in range(n):
            for j in range(m, A[i]-1, -1):
                dp[j] = max(dp[j-A[i]] + V[i], dp[j])
        return dp[m]