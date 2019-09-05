"""
https://leetcode-cn.com/problems/add-two-numbers/

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        head = ListNode(0)  # 头节点的指针
        p = head
        p1 = l1
        p2 = l2
        carry = 0  # 是否进位
        while p1 and p2:
            s, carry = self.ifcarry(p1.val, p2.val, carry)
            p.next = ListNode(s)
            p, p1, p2 = p.next, p1.next, p2.next
        p1 = p1 if p1 else p2
        while carry:
            if p1:
                s, carry = self.ifcarry(p1.val, carry)
                p.next = ListNode(s)
                p, p1 = p.next, p1.next
            else:
                p.next = ListNode(carry)
                p = p.next
                break
        p.next = p1
        return head.next

    def ifcarry(self, x, y, c=0):
        """
        是否进位
        """
        carry = 0
        s = x + y + c
        if s >= 10:
            s = s - 10
            carry = 1
        return s, carry

