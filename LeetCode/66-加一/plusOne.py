"""
https://leetcode-cn.com/problems/plus-one

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

"""
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        提示：模拟进位
        """
        carry = 1  # 把加以理解为进位
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += carry
            carry = 0
            if digits[i] >= 10:
                digits[i] %= 10
                carry = 1
                if i == 0:
                    digits.insert(0, carry)
        return digits
