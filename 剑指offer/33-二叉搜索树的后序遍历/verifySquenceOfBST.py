# -*- coding:utf-8 -*-
"""
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出 True,否则输出 False。假设输入的数组的任意两个数字都互不相同。
(二叉搜索树的左子树节点的值都小于根节点值，右子树节点的值都大于根节点的值)
"""

class Solution:

    def VerifySquenceOfBST(self, sequence):
        # write code here

        if not sequence:
            return False
        part = self.partition(sequence)
        if sequence[:part]:
            if sequence[part:-1]:
                return self.judge(sequence, part) and self.VerifySquenceOfBST(sequence[:part]) \
                       and self.VerifySquenceOfBST(sequence[part:-1])
            else:
                return self.judge(sequence, part) and self.VerifySquenceOfBST(sequence[:part])
        else:
            if sequence[part:-1]:
                return self.judge(sequence, part) and self.VerifySquenceOfBST(sequence[part:-1])
            else:
                return self.judge(sequence, part)


    def partition(self, sequence):
        """
        找到把左右子树分开的位置
        比如：
        [1, 2, 3, 5]，输出 3；
        [9, 8, 7, 5]，输出 0；
        [1, 2, 6, 5]，输出 2；
        """
        if sequence:
            for x in sequence:
                if x >= sequence[-1]:
                    return sequence.index(x)


    def judge(self, sequence, part):
        """
        以 part 为分界，若满足：
        左边元素小于最后一个元素，右边元素（不包含最后一个元素）大于最后一个元素，
        则返回 True
        """
        if sequence[:part]:
            for x in sequence[:part]:
                if x > sequence[-1]:
                    return False
        if sequence[part:-1]:
            for x in sequence[part:-1]:
                if x < sequence[-1]:
                    return False
        return True


if __name__ == "__main__":
    sequence = [4, 8, 6, 12, 16, 14, 10]
    f = Solution()
    print(f.VerifySquenceOfBST(sequence))

