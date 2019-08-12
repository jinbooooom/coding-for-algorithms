# -*- coding:utf-8 -*-
"""
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。

            1
          /   \
        2      3
      /  \      \
    4     5      7

输出：[[1], [3, 2], [4, 5, 7]]
"""

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def Print(self, pRoot):
        # write code here

        if pRoot is None:
            return []
        queue = [pRoot]
        deep = 1
        LValue = []
        while queue:
            thisLayer = queue[:]
            del queue[:]
            tValue = []
            if self.way(deep) == 'rightToLeft':
                [tValue.append(node.val) for node in thisLayer[::-1]]
            else:
                [tValue.append(node.val) for node in thisLayer]
            LValue.append(tValue)
            for node in thisLayer:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if queue:
                deep += 1
        return LValue

    def way(self, deep):
        if deep & 1:  # 奇数
            return 'leftToRight'
        else:
            return 'rightToLeft'






