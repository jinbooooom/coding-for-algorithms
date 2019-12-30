

# -*- coding:utf-8 -*-
"""
给定 n 个大小为 nums[i] 的物品，无重复。
整数 target 表示背包的大小。
在 nums 里挑选（可以重复挑选）一些物品，使其恰好能填充整个背包。
有多少种挑选方案？

例：
输入 nums = [2, 3, 6, 7]，target 7,

输出 2。
解析：
    共两种方案，[2, 2, 3] 和 [7]
"""


class Solution:
    """
    @param nums: an integer array and all positive numbers, no duplicates
    @param target: An integer
    @return: An integer
    """
    def backPackIV(self, nums, target):
        """
        提示:
        令 dp[j] 为容量为 j 的背包的方案数。
        当放入物品 nums[i]，有方案数 dp[j - nums[i]]；
        当不放入物品 nums[i]，有方案数 dp[j]。
        故总的方案数 dp[j] = dp[j - nums[i]] + dp[j]

        【记忆】
        将完全背包问题里面的 max 改为 sum，且初始化时将 dp[0] 设为 1；
        因为背包容量为 0 时，只有一种放入方法：什么都不放。

        """
        # write your code here
        n = len(nums)
        if n <= 0 or target < 0:
            return 0
        dp = [0 for _ in range(target+1)]
        dp[0] = 1
        for i in range(n):
            for j in range(nums[i], target+1):
                # dp[j] = sum([dp[j - nums[i]], dp[j]])
                dp[j] = dp[j - nums[i]] + dp[j]
        return dp[-1]


if __name__ == "__main__":
    nums = [2, 3, 6, 7]
    target = 7
    f = Solution()
    print(f.backPackIV(nums, target))


