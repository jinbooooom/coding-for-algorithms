/**
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树与此二叉树的镜像是同样的，定义其为对称的。
*/

class Solution {
public:
    // 法一：
    // 判断树的左子结点与右子节点是否相等，若是，则递归判断下去
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return isSame(pRoot->left, pRoot->right);
    }

    bool isSame(TreeNode* pL, TreeNode* pR)
    {
        if (pL == nullptr && pR == nullptr)  // 左右结点同时为空，对称
            return true;
        if (pL == nullptr || pR == nullptr)  // 左右节点一个为空一个不为空，就说明不对称
            return false;
        if (pL->val != pR->val)
            return false;
        else
            return isSame(pL->left, pR->right) && isSame(pL->right, pR->left);
    }

    // 法二：若树对称，那么按根左右顺序打印的结果肯定和按根右左的顺序打印的结果一样
    bool isSymmetrical2(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        vector<TreeNode*> vLR, vRL;
        traversalLR(pRoot, vLR);
        traversalRL(pRoot, vRL);
        // 有指针的比较大小一定要先判断指针是否为空，提领空指针会报段错误
        for (unsigned int i = 0; i < vLR.size(); ++i)
            if (vLR[i] == nullptr && vRL[i] == nullptr)
                continue;
            else if (vLR[i] == nullptr || vRL[i] == nullptr)
                return false;
            else if(vLR[i]->val != vRL[i]->val)
                return false;
        return true;
    }
    // 前序遍历，铵根左右的顺序把结点指针都存放到 vec 里（传引用）
    void traversalLR(TreeNode* pRoot, vector<TreeNode*>& vec)
    {
        if (pRoot == nullptr)
            vec.push_back(pRoot);
        else
        {
            vec.push_back(pRoot);
            traversalLR(pRoot->left, vec);
            traversalLR(pRoot->right, vec);
        }
    }
    // 按根右左的顺序把结点指针都存放到 vec 里（传引用）
    void traversalRL(TreeNode* pRoot, vector<TreeNode*>& vec)
    {
        if (pRoot == nullptr)
            vec.push_back(pRoot);
        else
        {
            vec.push_back(pRoot);
            traversalRL(pRoot->right, vec);
            traversalRL(pRoot->left, vec);
        }
    }
};
