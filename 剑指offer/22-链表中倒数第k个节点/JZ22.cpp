/*
倒数第 k 个结点就意味着该结点再走 k-1 次就可以到达尾结点，
那么当一个快指针先从头结点处移动 k-1 次，然后快指针与慢指针同时移动，
当快指针到底尾节点，慢指针就刚好到达了倒数第 k 个结点
*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0)  // 倒数第 0 个节点不存在
            return nullptr;
        ListNode* pSlow = pListHead;
        ListNode* pFast = pListHead;
        unsigned int cnt = 1;
        while (cnt < k)
        {
            if (pFast->next)
                pFast = pFast->next;
            else            // 当 k 超过链表长度的时候
                return nullptr;
            cnt++;
        }
        while(pFast->next)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};