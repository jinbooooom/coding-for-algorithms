# -*- coding:utf-8 -*-
"""
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
"""


class Solution:
    def __init__(self):
        self.stack1 = []  # 用于压入
        self.stack2 = []  # 用于弹出

    def push(self, node):
        # write code here
        self.stack1.append(node)

    def pop(self):
        """
        提示：
        栈只能先入先出，而队列是先入后出。如果 stack1 非空，stack2 为空，
        队列执行出队操作时，把 stack1 的元素 pop 出来存到 stack2 中，
        在 stack2 中执行 pop 操作就类似于出队操作了。
        """
        # return xx
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        if self.stack2:
            return self.stack2.pop()
