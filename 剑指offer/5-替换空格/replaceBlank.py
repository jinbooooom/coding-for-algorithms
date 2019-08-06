# -*- coding:utf-8 -*-
"""
实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
"""


class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        t = ''
        for i in s:
            if i == ' ':
                i = '%20'
            t += i
        return t
