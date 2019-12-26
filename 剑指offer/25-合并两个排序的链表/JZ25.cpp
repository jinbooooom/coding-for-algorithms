/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        else if (pHead2 == nullptr)
            return pHead1;

        ListNode* head = nullptr;
        if (pHead1->val < pHead2->val)
        {
            head = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            head = pHead2;
            pHead2 = pHead2->next;
        }

        ListNode* p = head;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
                p = p->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
                p = p->next;
            }
        }

        if (pHead1)
            p->next = pHead1;
        else if (pHead2)
            p->next = pHead2;
        return head;
    }
};









