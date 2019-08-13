# -*- coding:utf-8 -*-
"""
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
"""


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def Convert(self, pRootOfTree):
        """
        提示：
        在搜索二叉树中，左子节点的值总是小于父节点的值，右子节点的值总是大于父节点的值。
        把二叉搜索树转换为排序双向链表，我们使二叉搜索树某节点左指针指向它的左子树最大值（最右边）的节点，
        右指针指向它的右子树值最小（最左边）的节点。
        然后对每一个子树用同样操作。
        """
        # write code here

        if pRootOfTree is None:
            return None
        self.search(pRootOfTree)
        return self.getLeft(pRootOfTree)

    def search(self, root):
        """
        对左右子树的操作
        """
        if root.left:
            right = self.getRight(root.left)  # 先保存左子树的最右（大）节点
            self.search(root.left)  # 此时左子树已经转换成一个排序的双向链表
            root.left = right
            right.right = root
        if root.right:
            left = self.getLeft(root.right)
            self.search(root.right)
            root.right = left
            left.left = root

    def getLeft(self, root):
        """
        root非空，找树的最左边节点
        """
        while root.left:
            root = root.left
        return root

    def getRight(self, root):
        """
        root 非空，找树的最右边节点
        """
        while root.right:
            root = root.right
        return root


