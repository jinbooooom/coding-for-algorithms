# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/valid-number

验证给定的字符串是否可以解释为十进制数字。

例如:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

说明: 我们有意将问题陈述地比较模糊。
在实现代码之前，你应当事先思考所有可能的情况。
这里给出一份可能存在于有效十进制数字中的字符列表：

    数字 - 0-9
    指数 - "e"
    正/负号 - "+"/"-"
    小数点 - "."

当然，在输入中，这些字符的上下文也很重要。

"""


class Solution:
    """
    指数 e 后面只能是数字
    """
    def isNumber(self, s: str):
        """
        提示：
        考虑所有情况，下面这些情况肯定不是数字：
        1、如果当前字符是小数点，且前面已经出现过小数点或者 'e'；
        2、如果当前字符是 'e'，且前面已经出现过 'e'，或者前面没有出现过数字；
        3、如果 '+-' 不是出现在最开始，或者不是紧跟在 'e' 后
        4、如果串为空，或者只含有 '.' 或者只含有 '+-'，而没有数字出现

        """
        s = s.strip()
        dot_seen = False
        e_seen = False
        num_seen = False
        for i, a in enumerate(s):
            if a.isdigit():
                num_seen = True
            # 情况 1
            elif a == ".":
                if e_seen or dot_seen:
                    return False
                dot_seen = True
            # 情况 2
            elif a == "e":
                if e_seen or not num_seen:
                    return False
                num_seen = False
                e_seen = True
            # 情况 3
            elif a in "+-":
                if i > 0 and s[i - 1] != "e":
                    return False
            else:
                return False
        # 情况 4
        return num_seen

    def isNumber2(self, s: str):
        """
        提示：有限状态机 FSM
        状态转移图见同目录下 FSM.png

        {"digit": 5, "e": 6, "blank": 9} 的意思是在当前状态：
        如果接收到一个数字 digit，就会转移到状态 5；
        如果接收到 'e'，就会转移到状态 6；
        如果接收到空格 'blank'，就会转移到状态 9
        """
        state = [
                {},
                # 状态1,初始状态(扫描通过的空格)
                {"blank": 1, "sign": 2, "digit": 3, ".": 4},
                # 状态2,发现符号位(后面跟数字或者小数点)
                {"digit": 3, ".": 4},
                # 状态3,数字(一直循环到非数字)
                {"digit": 3, ".": 5, "e": 6, "blank": 9},
                # 状态4,小数点(后面只有紧接数字)
                {"digit": 5},
                # 状态5,小数点之后(后面只能为数字,e,或者以空格结束)
                {"digit": 5, "e": 6, "blank": 9},
                # 状态6,发现e(后面只能符号位, 和数字)
                {"sign": 7, "digit": 8},
                # 状态7,e之后(只能为数字)
                {"digit": 8},
                # 状态8,e之后的数字后面(只能为数字或者以空格结束)
                {"digit": 8, "blank": 9},
                # 状态9, 终止状态 (如果发现非空,就失败)
                {"blank": 9}]

        # 初始状态为状态 1
        cur_state = 1
        for c in s:
            if c.isdigit():
                c = "digit"
            elif c in " ":
                c = "blank"
            elif c in "+-":
                c = "sign"
            if c not in state[cur_state]:
                return False
            cur_state = state[cur_state][c]
        if cur_state not in [3, 5, 8, 9]:
            return False
        return True


