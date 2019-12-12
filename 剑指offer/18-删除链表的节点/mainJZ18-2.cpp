// 递归方法本地调试通过，牛客网栈溢出
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)  // 链表为空或者只有一个节点
            return pHead;
        ListNode* pNext = pHead->next;
        if(pHead->val != pNext->val)
        {
            pHead->next = deleteDuplication(pNext);
            return pHead;
        }
        while(pHead->val == pNext->val && pNext != nullptr)
        {
            pNext = pNext->next;
        }
        if(pHead->val != pNext->val)        // 说明 pHead 到 pNext 之前的值都重复，应该删去
        {
            pHead = deleteDuplication(pNext);
            return pHead;
        }
        else								// 从 pHead 到尾节点的节点值都重复，全部删去
        {
            pHead = nullptr;
            return pHead;
        }
    }
};