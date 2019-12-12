class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec;
        if (root == nullptr)
            return vec;

        queue<TreeNode*> queueNode;
        queueNode.push(root);

        while (!queueNode.empty())
        {
            TreeNode* pNode = queueNode.front();
            queueNode.pop();
            vec.push_back(pNode->val);
            if (pNode->left)
                queueNode.push(pNode->left);
            if (pNode->right)
                queueNode.push(pNode->right);
        }
        return vec;
    }
};