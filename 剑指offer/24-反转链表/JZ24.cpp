/*
输入一个链表，反转链表后，输出新链表的表头。
*/

class Solution
{
public:
    /**
     * 用多个指针分别记录当前节点，以及它的前驱和后继。
    */
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) // 链表为空或者只含有一个结点
            return pHead;

        ListNode *pre = nullptr;
        ListNode *pNode = pHead;
        ListNode *pNext = pNode->next;

        while (pNext)
        {
            pNode->next = pre;
            pre = pNode;
            pNode = pNext;
            pNext = pNode->next;
        }
        // 此时 pNext 为空，pNode 为头结点
        pNode->next = pre;
        return pNode;
    }
};