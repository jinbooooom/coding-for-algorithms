# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/interleaving-string

给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true

示例 2:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false

"""

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        """
        提示:
        用 dp[i][j] 表示 s1 的前 i 个字符（包括第 i 个字符） s1[:i] 和 s2 前 j 个字符 s2[:j] 是否交错组成 s3 前 i+j 字符 s3[:i+j-1]。
        若是，则需要满足下列条件之一：
        1、s1 的前 i-1 个字符 s1[:i-1] 和 s2 的前 j 个字符 s2[:j] 已经交错组成 s3 的前 i+j-1 字符 s3[:i+j-1]，
            且 s3[:i+j-1] 的下一个字符 s3[i+j-1] 与 s1[:i-1] 的下一个字符 s1[i-1] 相同；
        2、s1 的前 i 个字符 s1[:i] 和 s2 的前 j-1 个字符 s2[:j-1] 已经交错组成 s3 的前 i+j-1 字符 s3[:i+j-1]，
            且 s3[:i+j-1] 的下一个字符 s3[i+j-1] 与 s2[:j-1] 的下一个字符 s2[j-1] 相同；

        因此，当 i, j 大于 0 时，状态转移方程为：
        dp[i][j] = (dp[i-1][j] and s3[i+j-1] == s1[i-1]) || (dp[i][j-1] and s2[j-1] == s3[i+j-1])

        对边界，由于 s 的前 1 个字符指 s[0], s 的前 0 个字符指 s[-1]，这是不存在的，前 0 个字符表明 s 为空。
        那么 dp[0][j] 就是只有 s2 存在，判断 s2 的前 j 个字符与 s3 的前 j 个字符是否相等，相等的条件是：
        s2 的前 j-1 个字符与 s3 的前 j-1 个字符已经相等，且 s2 中索引为 j-1 的字符与 s3 中索引为 j-1 的字符相等。
        此时状态转移方程为：
        dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]

        同理 dp[i][0] 的状态转移方程为：
        dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]

        """
        n1 = len(s1)
        n2 = len(s2)
        n3 = len(s3)
        if n1 + n2 != n3: return False

        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]

        dp[0][0] = True
        # 第一行，i = 0, dp[0][j]
        for j in range(1, n2 + 1):
            dp[0][j] = (dp[0][j - 1] and s2[j - 1] == s3[j - 1])

        # 第一列，j = 0, dp[i][0]
        for i in range(1, n1 + 1):
            dp[i][0] = (dp[i - 1][0] and s1[i - 1] == s3[i - 1])

        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or (
                        dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[-1][-1]
