# -*- coding-utf-8 -*-
"""
https://leetcode-cn.com/problems/palindrome-partitioning

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。

示例:
输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

"""

from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s:
            return [s]
        for i in range(len(s)):
            return s[:i] + self.search(s)

    def search(self, s):
        if not s:
            return s




if __name__ == "__main__":
    f = Solution()
    result = f.partition("123")
    print(result)

