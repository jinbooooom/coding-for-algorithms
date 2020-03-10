# -*- coding:utf-8 -*-
"""
牛客最近来了一个新员工 Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事 Cat 对 Fish 写的内容颇感兴趣，有一天他向 Fish 借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat 对一一的翻转这些单词顺序可不在行，你能帮助他么？
"""

class Solution:
    def ReverseSentence(self, s):
        """
        提示：
        对于 C++ 可以先实现一个函数，以反转字符串的某一段，首先对整个字符串反转，再对每个单词反转。
        对于 Python 直接将字符串通过空格分割成各个单词，将每个单词翻转后再拼接，再对拼接后的字符串翻转。
        """
        # write code here
        if not s:
            return s

        words = s.split()
        # 当 s 只由空格组成，此时 words 为空
        if not words:
            return s

        res = ""
        for word in words:
            res += word[::-1] + " "
        res = res[::-1]
        # 最后一个单词后不应该添加空格，实际上也添加了，翻转后字符串首部有空格
        res = res[1:]
        return res
