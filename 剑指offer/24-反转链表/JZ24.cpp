class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr)  // 链表为空或者只含有一个结点
            return pHead;

        ListNode* pre = nullptr;
        ListNode* pNode = pHead;
        ListNode* pNext = pNode->next;
        pNode->next = pre;

        while (pNext)
        {
            if (pNext->next)
            {
                ListNode* pNextNext = pNext->next;
                pre = pNode;
                pNode = pNext;
                pNext = pNextNext;
                pNode->next = pre;
            }
            else
            {
                pNext->next = pNode;
                return pNext;
            }
        }
    }
};