# -*- coding:utf-8 -*-
"""
题目：
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
"""

# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None


class Solution:
    def getNext(self, pNode):
        """
        提示：
        分为两大类：
            1、有右子树的，那么下个结点就是右子树最左边的节点；
            2、没有右子树的，也可以分成两类:
                a) 是父节点左孩子，那么父节点就是下一个节点 ；
                b) 是父节点的右孩子，找他的父节点的父节点的父节点...直到当前结点是其父节点的左孩子。
                   如果没有，那么他就是尾节点。
        """
        # write code here
        if not pNode:
            return None
        if pNode.right:  # 若有右子树
            tmp = pNode.right
            while tmp.left:  # 找右子树最左边的节点
                tmp = tmp.left
            return tmp
        else:  # 若无右子树
            tmp = pNode.next
            while tmp:  # 若没有退到根节点，毕竟 root.next = None
                if pNode == tmp.left:  # 是父节点左孩子，那么父节点就是下一个节点
                    return tmp
                else:
                    tmp = tmp.next  # 是父节点的右孩子，找他的父节点的父节点的父节点...直到当前结点是其父节点的左孩子
                    pNode = pNode.next





