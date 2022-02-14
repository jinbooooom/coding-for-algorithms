/**
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr)  // 空树不是任何一个树的子结构
        {
            if (pRoot1->val == pRoot2->val)  // 根节点相等的时候，才逐个比较两树的结点
                result = isSubTree(pRoot1, pRoot2);
            if (!result)  // 根结点虽相同，但其他结点不同时，寻找 pRoot1 的左右子节点中是否有子树 pRoot2
                result = HasSubtree(pRoot1->left, pRoot2) ||
                		HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }

    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)  // 只要 pRoot2 为空，就说明遍历完了子树，返回 true
            return true;
        if (pRoot1 == nullptr)  // 必须先判断 pRoot2，在判断 pRoot1 是否为空
            return false;
        if (pRoot2->val != pRoot1->val)
            return false;
        else
            return isSubTree(pRoot1->left, pRoot2->left) &&
            		isSubTree(pRoot1->right, pRoot2->right);
    }
};