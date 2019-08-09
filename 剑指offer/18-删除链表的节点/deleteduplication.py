# -*- coding:utf-8 -*-
"""
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplication(self, pHead):
        # write code here

        if pHead is None or pHead.next is None:
            # 若为空链表或者只含有一个节点，那自然不会有重复的，直接返回就好
            return pHead

        pNext = pHead.next

        if pHead.val != pNext.val:
            # pHead.val 与 pNext.val 不相等，至少可以判断 pHead 不会是重复的节点，但 pNext 就不一定了。
            # 所以这里保留 PHead，并使 PHead 的指针域指向 self.deleteDuplication(pNext) 的头节点。
            pHead.next = self.deleteDuplication(pNext)
            return pHead
        else:
            while pHead.val == pNext.val and pNext.next is not None:
                pNext = pNext.next
            if pHead.val != pNext.val:
                # 从 pHead.next 到 pNext 的前面一个节点都应该被删除，
                # 所以直接让 pHead 而不是 pHead.next 指向 self.deleteDuplication(pNext) 的头节点
                pHead = self.deleteDuplication(pNext)
                return pHead
            else:  # pNext 指向 None，到了尾部
                return None




