# -*- coding：utf-8 -*-
"""
https://leetcode-cn.com/problems/valid-palindrome

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false

"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        提示：
        令双指针分别指向字符串的首尾，然后从两边向中间逼近。
        如果遇到数字和字符就判断双指针指向的字符是否相等，否则指针向中间逼近，直到双指针相遇。

        """
        left = 0
        right = len(s) - 1
        while right > left:
            while right > left and not s[right].isalnum():
                right -= 1
            while right > left and not s[left].isalnum():
                left += 1
            if s[right].lower() == s[left].lower():
                right -= 1
                left += 1
            else:
                return False
        return True