# -*- coding:utf-8 -*-
"""
题目：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
"""

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        """
        提示：
        非常类似归并排序的归并过程：
        若两链表任何一个为空，则返回剩下的那一个；
        若均不为空，则找到两个链表中值小的那个，添加到新链表尾部；
        若最后有某一个链表为空，说明它的节点都被添加到新链表上，直接把另一个非空链表剩下部分添到到新链表尾部
        """
        # write code here

        if pHead1 is None:
            return pHead2
        if pHead2 is None:
            return pHead1

        p1 = pHead1
        p2 = pHead2
        if pHead1.val < pHead2.val:
            head = p1
            p1 = p1.next
        else:
            head = p2
            p2 = p2.next

        p = head

        while p1 and p2:
            if p1.val < p2.val:
                p.next = p1
                p = p.next
                p1 = p1.next
            else:
                p.next = p2
                p = p.next
                p2 = p2.next

        if p1:
            p.next = p1
        if p2:
            p.next = p2
        return head












