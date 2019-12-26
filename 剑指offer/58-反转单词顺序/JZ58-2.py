# -*- coding:utf-8 -*-
"""
题目：左旋转字符串
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列 S，请你把其循环左移 K 位后的序列输出。
例如，字符序列 S=”abcXYZdef”,要求输出循环左移 3 位后的结果，即 “XYZdefabc”。
"""


class Solution:
    def LeftRotateString(self, s, n):
        """
        提示：
        将字符串分成两部分 s[:n] 和 s[n:]，分别翻转这两部分，然后再对整个字符串翻转。
        """
        # write code here
        pass