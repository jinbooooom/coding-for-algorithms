/*
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。

            1
          /   \
        2      3
      /  \      \
    4     5      7

输出：[[1], [3, 2], [4, 5, 7]]
*/

class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> vec2d;
        if (pRoot == nullptr)
            return vec2d;
        int deep = 1;
        vector<int> vec;
        vector<TreeNode *> vecNode{pRoot};

        while (!vecNode.empty())
        {
            vector<TreeNode *> thisLayer(vecNode);
            if (deep % 2 == 0)
                reverse(thisLayer);
            for (int i = 0; i < thisLayer.size(); ++i)
            {
                vec.push_back(thisLayer[i]->val);
            }
            vec2d.push_back(vec);
            vec.clear();
            vecNode.clear();
            if (deep % 2 == 0) //翻转完了再翻转回来
                reverse(thisLayer);

            for (int i = 0; i < thisLayer.size(); ++i)
            {
                if (thisLayer[i]->left != nullptr)
                    vecNode.push_back(thisLayer[i]->left);
                if (thisLayer[i]->right != nullptr)
                    vecNode.push_back(thisLayer[i]->right);
            }
            thisLayer.clear();
            deep++;
        }
        return vec2d;
    }

    void reverse(vector<TreeNode *> &vec)
    {
        int length = vec.size();
        for (int i = 0; i < length / 2; ++i)
        {
            TreeNode *pTmp = vec[i];
            vec[i] = vec[length - 1 - i];
            vec[length - 1 - i] = pTmp;
        }
    }
};