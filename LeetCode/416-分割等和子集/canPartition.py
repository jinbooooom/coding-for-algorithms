# -*- coding:utf-8 -*
"""
https://leetcode-cn.com/problems/partition-equal-subset-sum
https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
    每个数组中的元素不会超过 100
    数组的大小不会超过 200

示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].

示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.

"""
from typing import List


class Solution:
    def canPartition(self, nums: list) -> bool:
        """
        提示:
        方法一：二维动态规划

        可以把这道题转换为 0-1 背包问题：
        有一些物品，它们的重量存储在列表 nums 中，
        而你刚好有两个包，怎么装能让这两个包装的物品重量相等？
        或者说，你只有一个包，怎么让这一个包刚好带走总重量一半的物品？

        0-1 背包问题也是最基础的背包问题，它的特点是：待挑选的物品有且仅有一个，可以选择也可以不选择。
        下面我们定义状态，不妨就用问题的问法定义状态。

        dp[i][j]：表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和等于 j。
        新来一个数，例如是 nums[i]，这个数可能选择也可能不被选择：
        如果不选择 nums[i]，在 [0, i - 1] 这个子区间内已经有一部分元素，使得它们的和为 j ，那么 dp[i][j] = true；
        如果选择 nums[i]，在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i] (nums[i] <= j)。

        以上二者成立一条都行。于是得到状态转移方程：
        dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]], (if nums[i] <= j)

        """
        size = len(nums)
        # 特判，如果整个数组的和都不是偶数，就无法平分
        s = sum(nums)
        if s & 1 == 1:
            return False

        # 二维 dp 问题：背包的容量
        target = s // 2
        # 定义并初始化 size 行 target+1 列的备忘录
        dp = [[False for _ in range(target + 1)] for _ in range(size)]

        # 先写第 1 行：看看第 1 个数是不是能够刚好填满容量为 target
        for i in range(target + 1):
            dp[0][i] = False if nums[0] != i else True
        # i 表示物品索引
        for i in range(1, size):
            # j 表示容量
            for j in range(target + 1):
                if j >= nums[i]:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]
                else:
                    dp[i][j] = dp[i - 1][j]
        return dp[-1][-1]

    def canPartition2(self, nums: List[int]) -> bool:
        """
        提示：
        方法二：优化成一维动态规划

        即是 01 背包求方案数的问题

        """
        s = sum(nums)
        if s & 1:
            return False;
        s = s // 2
        dp = [0 for _ in range(s + 1)]
        dp[0] = 1
        for x in nums:
            for j in range(s, x - 1, -1):
                dp[j] = dp[j - x] + dp[j]
        return bool(dp[-1])

    def canPartition3(self, nums: List[int]) -> bool:
        """
        提示：
        方法三：在方法二的基础上改进，更容易理解

        """
        s = sum(nums)
        if s & 1:
            return False;
        s = s//2
        dp = [False for _ in range(s + 1)]
        dp[0] = True
        for x in nums:
            for j in range(s, x - 1, -1):
                dp[j] = dp[j - x] or dp[j]
        return dp[-1]


if __name__ == "__main__":
    f = Solution()
    nums = [1, 5, 11, 5]
    f2 = f.canPartition2(nums)
    print(f2)
