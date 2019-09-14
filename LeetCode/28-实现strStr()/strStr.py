# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/implement-strstr

实现 strStr() 函数。给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

"""


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i: i + len(needle)] == needle:
                return i
        return -1

    def strStr2(self, haystack: str, needle: str) -> int:
        """
        提示：
        当 haystack = "abhehello"，needle = "hel"
        i 是 haystack 里的索引值，j 是 needle 里的索引值。
        当 i, j 索引处的字符相同时，i, j 同时自增，直到 i 索引的字符与 j 索引的最后一个字符相同。
        此时便在 haystack 里找到了 needle，索引 i-j 即是找到的第一个 needle 的位置。

        用例子来说明，当 i = 2, j = 0 时，两索引处的字符相等，i, j 同时自增；
        此时 i = 3, j = 1，两索引处的字符相等，i, j 同时自增；
        此时 i = 4, j = 2，两索引处的字符不等，i 重新退回到 i-j+1 位置，j 退回到索引为 0 的位置。

        """
        if not needle:
            return 0
        if not haystack:
            return -1
        i = j = 0
        while i <= len(haystack) - len(needle):
            while j < len(needle):
                if haystack[i] != needle[j]:
                    i = i - j + 1
                    j = 0
                    break
                else:
                    i += 1
                    j += 1
            if j == len(needle):
                return i - j
        return -1
