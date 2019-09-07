# -*- coding:utf-8 -*-
"""
题目：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
"""


class Solution:
    def IsPopOrder(self, pushV, popV):
        """
        按照 popV 里的顺序出栈，如果能把 pushV 出栈成空栈，说明 popV 是一种可能的弹出顺序。
        """
        # write code here
        p = 0

        while pushV and popV:
            print(p, pushV, popV)
            if pushV[p] == popV[0]:
                del pushV[p]
                del popV[0]
                p -= 1
            elif pushV[p] != popV[0] and p + 1 == len(pushV):
                return False
            else:
                p += 1
        return True


if __name__ == "__main__":
    pushV = [1, 2, 3, 4, 5]
    popV = [4, 5, 3, 2, 1]
    f = Solution()
    print(f.IsPopOrder(pushV, popV))
