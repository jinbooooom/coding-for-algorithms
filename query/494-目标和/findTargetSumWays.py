# -*- coding:utf-8
"""
https://leetcode-cn.com/problems/target-sum

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:
输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。

注意:
    数组的长度不会超过20，并且数组中的值全为正数。
    初始的数组的和不会超过1000。
    保证返回的最终结果为32位整数。

"""


class Solution:
    def findTargetSumWays(self, nums: list, S: int) -> int:
        """
        提示：0-1 背包问题，动态规划求解
        将题目转换为 0-1 背包问题：
        由于只有两个符号 + 和 -，假设有两个包，其中一个包 P 内的数前面都是正号，另一个包 N 内的数前面都是负号。
        从数组 nums 中挑选若干个数（可以为零个）放入包 P 中，剩下的都放入包 N 中。
        那么，原问题转化为：
        包 P 中的数字和减去包 N 中的数字和刚好为 S 时，包 P 有多少种装法？
        即求解问题 sum(P) - sum(N) = S，有多少种可能性。
        等式两边同时加 sum(P) + sum(N)，得：
        sum(P) + sum(N) + sum(P) - sum(N) = S + sum(P) + sum(N)
        2 * sum(P) = sum(nums) + S
        即 sum(P) = (sum(nums) + S)/2
        那么问题又转化为从 nums 中挑选若干个数，使其和为 (sum(nums) + S)/2，有多少种挑法？



        :param nums:
        :param S:
        :return:
        """
        if sum(nums) < S or (sum(nums) + S) % 2 == 1:
            return 0
        P = (sum(nums) + S) // 2
        dp = [[0 for _ in range(P + 1)] for _ in range(len(nums))]

        for i in range(len(nums)):
            for j in range(1, P + 1):
                if i == 0:
                    dp[i][j] = 1 if nums[i] == j else 0
                elif j == 0:
                    dp[i][j] = 1
                elif j > nums[i]:
                    print(dp[i-1][j] , dp[i][j - nums[i]])
                    dp[i][j] = dp[i-1][j] + dp[i][j - nums[i]]

        return dp[-1][-1]

    def findTargetSumWays2(self, nums: list, S: int) -> int:
        if sum(nums) < S or (sum(nums) + S) % 2 == 1:
            return 0
        P = (sum(nums) + S) // 2
        dp = [1] + [0 for _ in range(P)]
        for num in nums:
            for j in range(P,num-1,-1):
                dp[j] += dp[j - num]
        return dp[P]

    def findTargetSumWays3(self, nums: list, S: int) -> int:
        if sum(nums) < S or (sum(nums) + S) % 2 == 1:
            return 0
        P = (sum(nums) + S) // 2
        dp = [1] + [0 for _ in range(P)]
        for j in range(1, P + 1):
            cap = j
            for num in nums:
                if j >= num and cap >= num:
                    cap = cap-num
                    dp[j] += dp[cap - num]
        print(dp)
        return dp[P]


if __name__ == "__main__":
    f = Solution()
    nums = [1, 1, 1, 1, 1]
    nums2 = [1]
    S = 3
    S2 = 1
    print(f.findTargetSumWays3(nums, S))
