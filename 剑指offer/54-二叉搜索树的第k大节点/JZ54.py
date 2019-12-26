# -*- coding:utf-8 -*-
"""
题目：
给定一棵二叉搜索树，请找出其中的第 k 小的结点。例如：

        5
    3       7
2     4  6      8

按结点数值大小顺序第三小结点的值为 4。
"""

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # 返回对应节点TreeNode
    def __init__(self):
        self.L = []

    def KthNode(self, pRoot, k):
        """
        提示：
        二叉搜索树的中序遍历序列是有序的，直接找中序遍历序列的第 k 个元素

        """
        # write code here

        if pRoot is None or k == 0:
            return None
        self.inorder(pRoot)
        if k - 1 < len(self.L):
            return self.L[k - 1]
        else:
            return None

    def inorder(self, pRoot):
        if pRoot:
            self.inorder(pRoot.left)
            self.L.append(pRoot)
            self.inorder(pRoot.right)


"""
有时候没有必要定义一个全局变量
    def __init__(self):
        self.L = []
因为 Python 里对可变变量都是传引用 
"""

class Solution2:
    # 返回对应节点TreeNode

    def KthNode(self, pRoot, k):
        # write code here
        if pRoot is None or k == 0:
            return None
        L = []
        self.inorder(pRoot, L)
        if k - 1 < len(L):
            return L[k - 1]
        else:
            return None

    def inorder(self, pRoot, L):
        # global L
        if pRoot:
            self.inorder(pRoot.left, L)
            L.append(pRoot)
            self.inorder(pRoot.right, L)
