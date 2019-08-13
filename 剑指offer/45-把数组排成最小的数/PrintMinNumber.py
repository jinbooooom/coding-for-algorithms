# -*- coding:utf-8 -*-
"""
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
"""


class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        numbers = [str(x) for x in numbers]
        result = ''
        while numbers:
            m = self.newMin(numbers)
            result += m
            numbers.remove(m)
        return result

    def newMin(self, ss):
        if len(ss) > 1:
            m = ss[0]
            for s in ss[1:]:
                if self.compare(s, m) < 0:
                    m = s
            return m
        elif len(ss) == 1:
            return ss[0]
        else:
            return ''

    def compare(self, s1, s2):
        """
        python 中字符比较大小：
        '3' > '2'  # True
        '3' > ''  # True

        定义新的比较规则:
        s1 > s2 ?
        """
        if s1 + s2 > s2 + s1:
            return 1
        elif s1 + s2 < s2 + s1:
            return -1
        else:
            return 0

if __name__ == "__main__":
    a = [3, 32, 321]
    s1 = '321'
    s2 = '32'
    f = Solution()
    num = f.PrintMinNumber(a)
    print(num)