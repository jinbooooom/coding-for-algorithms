/**
 * 题目：
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
    /**
     *  提示：
        非常类似归并排序的归并过程：
        若两链表任何一个为空，则返回剩下的那一个；
        若均不为空，则找到两个链表中值小的那个，添加到新链表尾部；
        若最后有某一个链表为空，说明它的节点都被添加到新链表上，直接把另一个非空链表剩下部分添到到新链表尾部
    */
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        else if (pHead2 == nullptr)
            return pHead1;

        ListNode *head = nullptr;
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

        ListNode *p = head;
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
