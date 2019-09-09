# -*- coding:utf-8 -*
"""
https://leetcode-cn.com/problems/coin-change

给定不同面额的硬币 coins 和一个总金额 amount。
编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

示例 2:
输入: coins = [2], amount = 3
输出: -1

说明:
你可以认为每种硬币的数量是无限的。

"""
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        提示：
        完全背包问题，用动态规划求解
        令 dp[i] 为凑足总金额为 i 的钱需要的最少硬币数，则状态转换方程为：

                            0                       if i == 0
        dp(i) = /
               \
                min(dp[i], dp[i - coin] + 1)      if i >= coin，其中 coin 属于 coins。

        """
        # 使 amount+1 填充备忘录 dp，如果 dp 里的数据没有修改，那么一定大于 amount。
        # 所以在 return 的时候可以作判断，如果 dp[i] 未被修改，
        # 说明找不到合适的硬币凑成该金额，返回 -1 就行。
        dp = [amount + 1 for x in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return -1 if dp[amount] > amount else dp[amount]


if __name__ == "__main__":
    f = Solution()
    coins = [1, 2, 5]
    amount = 11
    print(f.coinChange(coins, amount))