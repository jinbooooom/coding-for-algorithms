/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        int rootValue = pre[0];
        TreeNode *tree = new TreeNode(rootValue);
        vector<int>::iterator itIndex = find(vin.begin(), vin.end(), rootValue);
        int index = itIndex - vin.begin();
        vector<int> left_pre(pre.begin() + 1, pre.begin() + index + 1);
        vector<int> left_vin(vin.begin(), vin.begin() + index);
        vector<int> right_pre(pre.begin() + index + 1, pre.end());
        vector<int> right_vin(vin.begin() + index + 1, vin.end());
        tree->left = reConstructBinaryTree(left_pre, left_vin);
        tree->right = reConstructBinaryTree(right_pre, right_vin);
        return tree;
    }
};