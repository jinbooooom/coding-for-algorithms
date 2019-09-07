# -*- coding:utf-8 -*-
"""
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树与此二叉树的镜像是同样的，定义其为对称的。
"""


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSymmetrical(self, pRoot):
        """
        法一：递归
        """
        # write code here
        if pRoot is None:
            return True
        if pRoot and pRoot.left is None and pRoot.right is None:  # 树只有一个节点，自然是对称的
            return True
        return self.search(pRoot.left, pRoot.right)

    def search(self, pl, pr):
        """
        用 search() 函数判断对称节点 pl, pr 是否相等，并且找到 pl, pr 的子节点对应的对称节点
        :param pl, param pr: 这两个指针不同时为 None
        """
        if pl is None and pr is None:  # 都为空节点，对称
            return True
        if (pl is None and pr) or (pl and pr is None):  # 一个为空节点一个不为空节点，就不对称
            return False
        return self.isSame(pl, pr) and self.search(pl.right, pr.left) and self.search(pl.left, pr.right)

    def isSame(self, pl, pr):
        """
        :param pl, param pr: 均不为 None
        """
        if pl.val == pr.val:
            return True
        else:
            return False

    def isSymmetrical2(self, pRoot):
        """
        法二：观察遍历输出的序列
        若二叉树对称，则其前序遍历（根左右的遍历方式）与根右左的遍历方式输出序列是一样的。
        但要注意一点，对于叶子节点其左右子节点为 None,则将 None 值存放到输出序列中，以确定树的结构。
        不然，两棵含 N 个节点的树，其节点值均为 D，无论用哪种方式遍历结果都一样，此时需输出 None 值，以确定树的结构。
        """
        # write code here

        L1 = []
        L2 = []
        self.rootLeftRight(pRoot, L1)
        self.rootRightLeft(pRoot, L2)
        return L1 == L2

    def rootLeftRight(self, pRoot, arr):
        if pRoot is None:
            arr.append(None)
        else:
            arr.append(pRoot.val)
            self.rootLeftRight(pRoot.left, arr)
            self.rootLeftRight(pRoot.right, arr)

    def rootRightLeft(self, pRoot, arr):
        if pRoot is None:
            arr.append(None)
        else:
            arr.append(pRoot.val)
            self.rootRightLeft(pRoot.right, arr)
            self.rootRightLeft(pRoot.left, arr)