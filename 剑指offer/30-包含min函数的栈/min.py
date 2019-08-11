# -*- coding:utf-8 -*-
"""
题目：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数 (时间复杂度应为 O(1))。
"""


class Solution:
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, node):
        # write code here
        if self.minStack == []:
            self.minStack.append(node)
        elif node <= self.minStack[-1]:
            self.minStack.append(node)
        self.stack.append(node)

    def pop(self):
        # write code here
        if self.stack[-1] == self.minStack[-1]:
            self.minStack.pop()
        return self.stack.pop()

    def top(self):
        # write code here
        return self.stack[-1]

    def min(self):
        # write code here
        return self.minStack[-1]