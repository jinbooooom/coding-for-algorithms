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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!(pHead1 && pHead2)) return nullptr;
        unsigned int length1 = getListLength(pHead1);
        unsigned int length2 = getListLength(pHead2);
        ListNode *pLong, *pShort;
        // 在 if...else...里定义 pLong 和 pShort 可不行，因为 {} 的作用域有限
        if (length1 >= length2)
        {
            pLong = pHead1;
            pShort = pHead2;
        }
        else
        {
            pLong = pHead2;
            pShort = pHead1;
        }
        for (int i = 0; i < abs(int(length1 - length2)); ++i)
            pLong = pLong->next;

        while (pLong && pShort && pLong != pShort)
        {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }

    unsigned int getListLength(ListNode* head)
    {
        unsigned int length = 0;
        ListNode* p = head;
        while (p)
        {
            length++;
            p = p->next;
        }
        return length;
    }
};