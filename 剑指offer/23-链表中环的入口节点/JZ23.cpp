class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;

        while (pFast)
        {
            if (pFast->next && pFast->next->next)
            {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
                if (pFast == pSlow)
                    break;
            }
            else  // 此时链表无环
                return nullptr;
        }

        pFast = pFast->next;
        int NodeOfLoop = 1;
        while (pFast != pSlow)
        {
            pFast = pFast->next;
            ++NodeOfLoop;
        }
        if (NodeOfLoop == 1)        // 环中只有一个结点，pSlow 就是环的入口结点
            return pSlow;

        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while (NodeOfLoop)
        {
            p2 = p2->next;
            NodeOfLoop--;
        }
        while (p1 != p2)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};