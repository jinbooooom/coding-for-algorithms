# -*- coding:utf-8 -*-
"""
题目：
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
"""

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def TreeDepth(self, pRoot):
        """
        提示：
        若该数有左右子树，则其深度为其子树深度 + 1（1为根）中大的那一个

        """
        # write code here
        if pRoot is None:
            return 0
        nLeft = self.TreeDepth(pRoot.left) + 1
        nRight = self.TreeDepth(pRoot.right) + 1
        return nLeft if nLeft >= nRight else nRight