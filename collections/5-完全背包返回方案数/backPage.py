# -*- coding:utf-8 -*-
"""
给定 n 个大小为 nums[i] 的正整数数组，无重复。
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
        将完全背包问题里面的 max 改为 sum，且初始化时将 dp[0] 设为 1；

        """
        # write your code here
        n = len(nums)
        if n <= 0 or target < 0:
            return 0
        dp = [0 for _ in range(target+1)]
        dp[0] = 1
        for i in range(n):
            for j in range(nums[i], target+1):
                dp[j] = dp[j - nums[i]] + dp[j]
        return dp[-1]


