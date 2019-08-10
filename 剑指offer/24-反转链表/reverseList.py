# -*- coding:utf-8 -*-
"""
输入一个链表，反转链表后，输出新链表的表头。
"""

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        """
        用多个指针分别记录当前节点，以及它的前驱和后继。
        """
        # write code here

        if pHead is None:
            return None
        else:
            if pHead.next:
                pre = None
                pNode = pHead
                pNext = pNode.next
                pNode.next = pre
            else:  # 链表只含有一个节点
                return pHead

        while pNext:
            if pNext.next:
                pNextNext = pNext.next
                pre = pNode
                pNode = pNext
                pNext = pNextNext
                pNode.next = pre
            else:  # pNext即是尾节点
                pNext.next = pNode
                return pNext






