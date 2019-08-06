# -*- coding:utf-8 -*-
"""
输入一个链表，按链表值从尾到头的顺序返回一个 ArrayList。
"""

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        """
        剑指 offer 里只说要逆序打印链表，这样用递归可以实现，因为递归本质上就是栈。
        但牛客网里要求将逆序链表存到列表 ArrayList中并返回，就不太好用递归实现了。
        """
        # write code here

        ArrayList = []
        while(listNode):
            ArrayList.insert(0, listNode.val)
            listNode = listNode.next
        return ArrayList
