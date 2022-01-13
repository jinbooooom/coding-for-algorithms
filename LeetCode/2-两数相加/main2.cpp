/**
https://leetcode-cn.com/problems/add-two-numbers/
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
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