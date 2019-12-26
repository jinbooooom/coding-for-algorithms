"""
题目：
输入两个链表，找出它们的第一个公共结点。
"""

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        """
        提示：
        假设链表 1 是 1->2->3->6->7，链表 2 是 4->5->6->7。
        法一：
        若有公共结点，那么从尾结点开始向前比较，那么最后一个相同的结点就是要找的公共结点，
        但由于是单链表不知道前驱，所以考虑用两个栈分别存储两链表结点，不断判断栈顶元素是否相同，找到最后一个相同的元素。
        代码略。

        法二：
        两链表有长有短，设长链表比短链表长 cnt，两个指针 pLong、pShort 分别指向长、短链表头，
        让 pLong 先在长链表上走动 cnt，再两指针同时走，遇到的第一个相同结点就是公共结点了。
        """
        # write code here
        if (not (pHead1 and pHead2)):  # 有一个为空就返回空
            return None
        length1 = self.getListLength(pHead1)
        length2 = self.getListLength(pHead2)
        if length1 >= length2:
            pLong = pHead1
            pShort = pHead2
        else:
            pLong = pHead2
            pShort = pHead1
        cnt = abs(length1 - length2)
        while cnt:
            pLong = pLong.next
            cnt -= 1
        while pLong and pShort and pLong != pShort:
            pLong = pLong.next
            pShort = pShort.next
        return pLong

    def getListLength(self, head):
        length = 0
        p = head
        while p:
            length += 1
            p = p.next
        return length