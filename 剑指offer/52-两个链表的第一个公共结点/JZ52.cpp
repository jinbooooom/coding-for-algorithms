/**
 * 题目：
 * 输入两个链表，找出它们的第一个公共结点。
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
        假设链表 1 是 1->2->3->6->7，链表 2 是 4->5->6->7。
        法一：
        若有公共结点，那么从尾结点开始向前比较，那么最后一个相同的结点就是要找的公共结点，
        但由于是单链表不知道前驱，所以考虑用两个栈分别存储两链表结点，不断判断栈顶元素是否相同，找到最后一个相同的元素。
        如果是这样，空间复杂度就不是 O(1)。
        代码略。

        法二：
        两链表有长有短，设长链表比短链表长 cnt，两个指针 pLong、pShort 分别指向长、短链表头，
        让 pLong 先在长链表上走动 cnt，再两指针同时走，遇到的第一个相同结点就是公共结点了。
    */
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!(pHead1 && pHead2))
            return nullptr;
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

    unsigned int getListLength(ListNode *head)
    {
        unsigned int length = 0;
        ListNode *p = head;
        while (p)
        {
            length++;
            p = p->next;
        }
        return length;
    }
};