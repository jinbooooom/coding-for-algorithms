# -*- coding:utf-8 -*-
"""
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
"""


# -*- coding:utf-8 -*-
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
        return self.search(pRoot1, pRoot2)

    def search(self, A, B):
        """
        search(A,B) 用于指定在树 A 的哪个节点上会找到一个子树跟 B 一样，用 isSubTree() 函数判断 A 中的某一个子树是否与 B 一样
        """
        if A.left and A.right:
            return self.search(A.left, B) or self.search(A.right, B) or self.isSubTree(A, B) \
                   or self.isSubTree(A.left, B) or self.isSubTree(A.right, B)
        if A.left:
            return self.search(A.left, B) or self.isSubTree(A, B) or self.isSubTree(A.left, B) \
                   or self.isSubTree(A.right, B)
        if A.right:
            return self.search(A.right, B) or self.isSubTree(A, B) or self.isSubTree(A.left, B) \
                   or self.isSubTree(A.right, B)

    def isSubTree(self, A, B):
        """
        把树 A 与 B 逐元素比对，判断 A 是否包含 B
        """
        if B is None:
            return True
        elif A is None or A.val != B.val:
            return False
        else:  # A 与 B 的 val 值相等
            return self.isSubTree(A.left, B.left) and self.isSubTree(A.right, B.right)





