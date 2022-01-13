/*
题目：
    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
    重复的结点不保留，返回链表头指针。
    例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        /*
        提示：
            对该题中一个排序的链表，如果它的头节点 Head 与下一个节点 pNext 不同，
            那么 Head 一定是不会重复的，但 pNext 就不一定了。
            因此再递归处理以 pNext 为头节点的子链表，使该子链表返回的头节点一定不重复。
            递归就是，后面的都已经处理好了。
        */
        if (pHead == nullptr || pHead->next == nullptr) // 链表为空或者只有一个节点
            return pHead;
        ListNode *pNext = pHead->next;
        if (pHead->val != pNext->val)
        {
            pHead->next = deleteDuplication(pNext);
            return pHead;
        }
        while (pHead->val == pNext->val && pNext->next != nullptr)
        {
            pNext = pNext->next;
        }
        // 若是不满足 pHead->val == pNext->val 而退出 while 循环，说明 pHead 到 pNext 之前的值都重复，应该删去
        if (pHead->val != pNext->val)
        {
            pHead = deleteDuplication(pNext);
            return pHead;
        }
        // 若是不满足 pNext != nullptr 而退出 while 循环，说明从 pHead 到尾节点的节点值都重复，全部删去
        else
        {
            pHead = nullptr;
            return pHead;
        }
    }
};