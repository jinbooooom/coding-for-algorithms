# -*- coding:utf-8 -*-
"""
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出 None。
"""


class Solution:

    def EntryNodeOfLoop(self, pHead):
        """
        提示：
        假设有环，且知道环中节点的个数设为 n，那么设置两个指针 p1, p2 分别指向头节点，现在使 p2 先移动 n 步，p1 不动，
        再使 p1, p2 同时移动，那么当 p1, p2 相遇时，p1 指针指向的节点就是入口节点。

        如何求环中节点个数 n?
        设置两个指针，一快一慢，最开始都指向头节点。快指针 pFast 每次移动 2 步，慢指针 pSlow 每次移动 1 步，
        若 pFast 能到达尾节点，则说明无环；
        若 pFast 能相遇，说明有环，当相遇时，慢指针 pSlow 保持位置不变，
        快指针改为每次移动 1 步，直到再次与慢指针相遇，移动了多少步，环中就含有多少个节点。
        """
        # write code here

        if pHead is None:
            return None
        pFast = pHead
        pSlow = pHead
        NodeOfLoop = 1  # 环有多少个节点，只要有环，则至少有一个节点

        while pFast:
            try:
                pFast = pFast.next.next
            except:
                return None
            else:
                pSlow = pSlow.next

            if pFast is pSlow:  # 两指针相遇了，pSlow不动，以作为相遇的点，pFast 改为每次走一步
                pFast = pFast.next
                while pFast is not pSlow:
                    NodeOfLoop += 1
                    pFast = pFast.next
                if NodeOfLoop == 1:  # 环中只有一个节点，说明尾节点的指针指向尾节点
                    return pSlow
                break

        p1 = p2 = pHead
        while NodeOfLoop:
            p2 = p2.next
            NodeOfLoop -= 1

        if p1 is not p2:
            while p1 is not p2:
                p1 = p1.next
                p2 = p2.next
                if p1 is p2:
                    return p1
        else:
            return p1

    def EntryNodeOfLoop2(self, pHead):
        """
        普通方法，一次遍历，但每次都要判断当前节点是否在辅助空间中存在。空间复杂度 O(n):
        将访问的节点都存放到列表中，查看下一个要访问的节点是否在列表中，
        若是，含有环，且该节点就是环的入口；
        若直到访问到尾节点，还是无重复节点，则无环。
        """

        # write code here

        pNode = pHead
        p = []

        while pNode:
            if pNode is None:
                return None
            else:
                if pNode in p:
                    return pNode
                else:
                    p.append(pNode)
                    pNode = pNode.next


if __name__ == "__main__":
    # 测试实例
    import sys
    sys.path.append("..")
    sys.path.append("./")
    import linkedList as l
    link = l.LinkedList()
    for x in [1, 2, 3, 4, 5, 6]:
        link.append(x)
    link.traverse()
    # link.head.next = link.head
    link.head.next.next.next.next.next.next = link.head.next.next.next
    n = 20
    p = link.head
    t = []
    while n:
        t.append(p.item)
        p = p.next
        n -= 1
    print(t)

    f = Solution()
    cross = f.EntryNodeOfLoop(link.head)
    print("环入口地址与入口节点的值分别为：")
    if cross:
        print(cross)
        print(cross.item)
    else:
        print(None)
