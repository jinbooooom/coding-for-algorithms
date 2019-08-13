# -*- coding:utf-8 -*-
"""
题目：(这个题目与剑指 offer 不同)
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串 aabc,
则打印出字符串中不同字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
"""


class Solution:
    def Permutation(self, ss):
        # write code here
        s = sorted(list(set([*ss])))
        print(s)
        return self.pailie(s, len(s))

    def pailie(self, s, n):
        if n < 2:
            return s
        yy = self.pailie(s, n - 1)
        t = [self.merge(x, y) for x in s for y in yy]
        t = [x for x in t if x]
        print(n, t)
        return t

    def merge(self, x, y):
        if x not in y:
            return x + y
        else:
            return None


if __name__ == "__main__":

    f = Solution()
    s = 'acba'
    f.Permutation(s)