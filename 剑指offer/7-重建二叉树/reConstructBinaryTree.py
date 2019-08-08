# -*- coding:utf-8 -*-
"""
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
"""


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        """
        提示：
        知道前序遍历 pre = [1,2,4,7,3,5,6,8]，则根节点的值必然是 pre[0]，
        由于中序遍历会以根节点把树分成左右两部分，所以找到 pre[0] 在中序遍历列表中的位置（设为 p），
        就可以以 p 为分界线分别找到左右子树的前序中序序列。

        :param pre: 前序遍历序列
        :param tin: 中序遍历序列
        :return: 树根节点
        """
        # write code here

        if pre and tin:
            tree = TreeNode(pre[0])
            p = tin.index(pre[0])  # 下标 p 将 tin 分成左子树和右子树两部分
            # 找到每一个子数的 root 节点的下标，再将其分为左子树和右子树
            tree.left = self.reConstructBinaryTree(pre[1:p+1], tin[:p])
            tree.right = self.reConstructBinaryTree(pre[p+1:], tin[p+1:])
            return tree

