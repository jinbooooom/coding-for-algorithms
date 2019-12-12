class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return;
        TreeNode *pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};