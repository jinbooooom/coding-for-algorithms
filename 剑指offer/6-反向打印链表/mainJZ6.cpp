/**
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