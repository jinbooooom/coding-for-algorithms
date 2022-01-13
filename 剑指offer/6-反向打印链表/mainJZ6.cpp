/**
 * 输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(nullptr) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head == nullptr)
            return vec;

        stack<ListNode*> stk;
        ListNode* pNode = head;

        while(pNode)
        {
            stk.push(pNode);
            pNode = pNode->next;
        }

        while(!stk.empty())
        {
            pNode = stk.top();
            vec.push_back(pNode->val);
            stk.pop();
        }
        return vec;
    }
};