# -*- coding:utf-8 -*-
"""
题目：
输入一个链表，输出该链表中倒数第 k 个结点。
"""


class Solution:
    def FindKthToTail(self, head, k):
        """
        提示：
        以数组为例，设数组长度为 n，倒数第 i 个元素就是索引为 n-i 的位置.
        设指针 p1 指向索引为 0 处，该指针移动 n-k 次，到达索引为 n-k 的位置，也即倒数第 k 个元素。
        设指针 p2 指向索引为 n-1 - (n-k) = k-1 的位置，则 p2 移动 n-k 次，
        就到达了索引为 n-1 的位置，也即数组尾。

        通俗来说就是，倒数第 1 个元素（数组最后一个元素）索引为 n-1，倒数第 k 个元素索引为 n-k。
        对索引为 n-k 的元素只要再移动 (n-1) - (n-k) = k-1 次就能与索引为 n-1 的元素处于同样的位置，
        如果设置两个指针 P1，P2。P1 指向索引为 0 处，P2 指向索引为 k-1 处，让 P1，P2 同时移动，
        P2 移动 (n-1) - (k-1) = n-k 次，到达索引为 (k-1) + (n-k) = n-1 的位置，
        同时 P1 也移动了 n-k 次，到达索引为 0 + (n-k) = n-k 的位置，即倒数第 k 个元素。

        对本题目首先让 p1，p2 指向头节点，让 p2 移动，直到移动了 k-1 次，p1 再开始移动。
        p2 移到了尾节点，又移动了 n-k，而 p1 移动同样的次数到达了 n-k 的节点，此时正好为倒数第 k 个节点。

        整个算法只遍历链表一次，不需要知道链表的具体长度。
        """
        # write code here
        if head is None:
            return None
        if k < 1:
            return None
        p1 = head
        p2 = head
        cnt = 1
        while cnt <= k - 1:
            if p2.next:
                p2 = p2.next
            else:
                return None
            cnt += 1
        while p2.next:
            p2 = p2.next
            p1 = p1.next
        return p1


class Node(object):
    def __init__(self, item):
        # 元素域
        self.item = item
        # 链接域
        self.next = None


class LinkedList(object):  # 单链表
    def __init__(self, node=None):
        self.head = node

    def __len__(self):  # size
        # 游标 cursor ，用来遍历链表
        cur = self.head
        # 记录遍历次数
        count = 0
        # 当前节点为None则说明已经遍历完毕
        while cur:
            count += 1
            cur = cur.next
        return count

    def add(self, item):  # 链表头部添加元素
        """
        头插法
        先让新节点的next指向头节点
        再让头节点指向新节点
        顺序不可错，要先保证原链表的链不断，否则头节点后面的链会丢失
        """
        node = Node(item)
        node.next = self.head
        self.head = node  # node是最新插入节点的地址

    def append(self, item):  # 链表尾部添加元素
        """尾插法"""
        node = Node(item)
        cur = self.head
        if self.isEmpty():
            self.head = node
        else:
            while cur.next:
                cur = cur.next
            cur.next = node

    def insert(self, pos, item):  # 指定位置添加元素,下标从零开始
        # 特殊情况，若 pos <= 0，使用头插法；若 pos >= len(list)，使用尾插法。
        if pos <= 0:
            self.add(item)
        elif pos >= len(self):
            self.append(item)
        else:
            cur = self.head
            node = Node(item)
            while pos - 1:
                # 从 0(self.__head) 到 pos 位置，cur 要移动 pos 次
                # 但只移动 pos - 1 就好，因为前面一个节点能找到后面的节点，后面的节点找不到前面的节点。
                cur = cur.next
                pos -= 1
            # cur 最终指向要插入的位置前面一个节点
            node.next = cur.next
            cur.next = node

    def remove(self, item):  # 删除值等于 item 的节点
        cur = self.head
        prior = None
        while cur:
            if cur.item == item:
                if cur == self.head:  # 如果删除第一个节点
                    self.head = self.head.next
                elif not cur.next:  # 如果删除最后一个节点
                    prior.next = None
                else:
                    prior.next = cur.next
                break  # 此时的 cur 始终为 True，得跳出。
            else:
                prior = cur
                cur = cur.next

    def search(self, item):  # 查找节点是否存在
        cur = self.head
        while cur:
            if cur.item == item:
                return True
            else:
                cur = cur.next
        return False

    def isEmpty(self):
        # 头节点不为 None 则不为空
        return not self.head

    def traverse(self):  # 遍历整个链表
        cur = self.head
        t = []
        while cur:
            t.append(cur.item)
            cur = cur.next
        print(t)


if __name__ == "__main__":
    a = LinkedList()
    f = Solution()
    for x in range(1, 6):
        a.append(x)
    a.traverse()
    k = 5
    p = f.FindKthToTail(a.head, k)
    if p:
        print("倒数第 {} 个数是：{}".format(k, p.item))
    else:
        print(None)







