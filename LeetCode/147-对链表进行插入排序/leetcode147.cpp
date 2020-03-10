/*
对链表进行插入排序
*/

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = insertionSortList(head->next);
        if (p2 == nullptr || p1->val <= p2->val)
        {
            p1->next = p2;
            return p1;
        }
        ListNode* prev = p2;
        ListNode* curr = p2->next;
        while (curr != nullptr && curr->val < p1->val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = p1;
        p1->next = curr;
        return p2;
    }
};