# -*- coding:utf-8 -*-
"""
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
            1
          /   \
        2      3
      /  \      \
    4     5      7

输出：[[1], [2, 3], [4, 5, 7]]
"""


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def Print(self, pRoot):
        """
        提示：
        把每一层节点都存到队列（列表）中
        """
        # write code here

        if pRoot is None:
            return []
        queue = [pRoot]
        LValue = []
        while queue:
            thisLayer = queue[:]
            del queue[:]
            tValue = []
            for node in thisLayer:
                tValue.append(node.val)
            LValue.append(tValue)
            for node in thisLayer:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return LValue