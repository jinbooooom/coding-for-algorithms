/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int s, x, y = 0;
        while (p1 || p2)
        {
            if (p1 && p2)
                s = p1->val + p2->val + carry;
            else if (p1 && !p2)
                s = p1->val + carry;
            else if (!p1 && p2)
                s = p2->val + carry;
            x = s % 10;
            carry = s / 10;
            p->next = new ListNode(x);
            p = p->next;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        if (carry)
            p->next = new ListNode(carry);
        return head->next;
    }
};