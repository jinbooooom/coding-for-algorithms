# -*- coding:utf-8 -*-
"""
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
"""

import re


class Solution:

    def isNumeric(self, s):
        # write code here

        # return re.match(r"^[+-]?[0-9]*(\.[0-9]*)?([eE][+-]?[0-9]+)?$",s)
        # if re.match(r"^[+-]?[0-9]+[0-9]*([\.]+[1-9]+[0-9]*)?([eE][+-]?[0-9]+)?$", s):
        if re.match(r"^[+-]?[0-9]*(\.[0-9]*)?([eE][+-]?[0-9]+)?$", s):
            return True
        else:
            return False

    def isNumeric2(self, s):
        # write code here
        try:
            float(s)
        except:
            return False
        return True

if __name__ == "__main__":
    f = Solution()
    ss = ['e2', '.e2', '009.e', '+.e-9']
    f1 = []
    f2 = []
    for s in ss:

        f1.append(f.isNumeric(s))
        f2.append(f.isNumeric2(s))
    print("两者在我的测试实例中，不一样，但在牛客网上均通过。很奇妙")
    print(f1)
    print(f2)

