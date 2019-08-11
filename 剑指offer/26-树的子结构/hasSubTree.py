# -*- coding:utf-8 -*-
"""
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
"""

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if pRoot1 is None or pRoot2 is None:
            return False
        return self.isSubTree(pRoot1, pRoot2) or self.isSubTree(pRoot1.left, pRoot2) \
               or self.isSubTree(pRoot1.right, pRoot2)
        # 总觉得这个 return 未考虑所有情况

    def isSubTree(self, A, B):
        if B is None:
            return True
        elif A is None or A.val != B.val:
            return False
        else:  # A 与 B 的 val 值相等
            return self.isSubTree(A.left, B.left) and self.isSubTree(A.right, B.right)

