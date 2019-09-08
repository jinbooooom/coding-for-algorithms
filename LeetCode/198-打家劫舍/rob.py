# -*- coding:utf:8 -*-
"""
https://leetcode-cn.com/problems/house-robber

你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

    ，AiA_iAi​ = 第 i 个房屋的钱数。

首先看 n = 1 的情况，显然 f(1) = A1A_1A1​。

再看 n = 2，f(2) = max(A1A_1A1​, A2A_2A2​)。

对于 n = 3，有两个选项:

    抢第三个房子，将数额与第一个房子相加。

    不抢第三个房子，保持现有最大数额。

显然，你想选择数额更大的选项。于是，可以总结出公式：

    f(k) = max(f(k – 2) + AkA_kAk​, f(k – 1))

我们选择 f(–1) = f(0) = 0 为初始情况，这将极大地简化代码。

答案为 f(n)。可以用一个数组来存储并计算结果。不过由于每一步你只需要前两个最大值，两个变量就足够用了。

作者：LeetCode
链接：https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        提示：动态规划
        令 dp[i] 为抢了在闭区间 [0, i] 的房子。则状态转移方程为：
        dp[i] = max(dp[i-1], dp[i-2] + nums[i])  if i>=2

        """
        size = len(nums)
        if size == 0:
            return 0
        elif size == 1:
            return nums[0]
        elif size == 2:
            return max(nums)

        dp = [0] * size
        dp[0], dp[1] = nums[0], max(nums[:2])
        for i in range(2, size):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return dp[-1]

