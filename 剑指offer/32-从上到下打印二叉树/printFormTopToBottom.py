# -*- coding:utf-8 -*-
"""
题目：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
"""

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        """
        提示：使用队列存储节点。
        根节点先入队，找到队头元素的左右孩子（如果有的话）入队，再使队头元素出队，
        此时会有新的队头元素，再找新队头的左右孩子入队，再使新队头出队。
        如此反复，直至出队操作使队列再次为空
        """
        # write code here
        if root is None:
            return []
        queue = [root]
        LValue = []
        while queue:
            this = queue.pop()
            LValue.append(this.val)
            if this.left:
                queue.insert(0, this.left)
            if this.right:
                queue.insert(0, this.right)
        return LValue




