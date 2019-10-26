# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/longest-palindromic-substring/
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"

"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        提示：
        二维动态规划问题。
        当 s[l] == s[r] 成立的时候，dp[l][r] 的值由 dp[l + 1][r - 1] 决定，即：
        当左右边界字符串相等的时候，整个字符串是否是回文就完全由 “原字符串去掉左右边界” 的子串是否回文决定。
        但是这里还需要再多考虑一点点：“原字符串去掉左右边界”的子串的边界情况。
        1、当原字符串的元素个数为 3 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 1 个字符，它一定是回文串，故原字符串也一定是回文串；
        2、当原字符串的元素个数为 2 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 0 个字符，显然原字符串也一定是回文串。
        把上面两点归纳一下，只要 s[l + 1, r - 1] 至少包含两个元素，就有必要继续做判断，
        否则直接根据左右边界是否相等就能得到原字符串的回文性。
        而 “s[l + 1, r - 1] 至少包含两个元素” 等价于 l + 1 < r - 1，整理得 r - l > 2。

        综上，如果一个字符串的左右边界相等，以下二者之一成立即可：
        1、去掉左右边界以后的字符串不构成区间，即 “s[l + 1, r - 1] 最多包含 1 个元素”，
            等价于 r - 1 <= l + 1，即 r - l <= 2；
        2、去掉左右边界以后的字符串是回文串，具体说，它的回文性决定了原字符串的回文性。

        于是整理成 “状态转移方程” ：
        dp[l, r] = (s[l] == s[r] and (r - l <= 2 or dp[l + 1, r - 1]))
        """
        size = len(s)
        if size <= 1:
            return s
        # 二维 dp 问题
        # 状态：dp[l,r]: s[l:r] 包括 l，r ，表示的字符串是不是回文串
        # 设置为 None 是为了方便调试，看清楚代码执行流程
        dp = [[False for _ in range(size)] for _ in range(size)]

        longest_l = 1
        res = s[0]

        # 因为只有 1 个字符的情况在最开始做了判断
        # 左边界一定要比右边界小，因此右边界从 1 开始
        for r in range(1, size):
            for l in range(r):
                # 状态转移方程：如果头尾字符相等并且中间也是回文
                # 在头尾字符相等的前提下，如果收缩以后不构成区间（最多只有 1 个元素），直接返回 True 即可
                # 否则要继续看收缩以后的区间的回文性
                # 重点理解 or 的短路性质在这里的作用
                if s[l] == s[r] and (r - l <= 2 or dp[l + 1][r - 1]):
                    dp[l][r] = True
                    cur_len = r - l + 1
                    if cur_len > longest_l:
                        longest_l = cur_len
                        res = s[l:r + 1]
        return res
