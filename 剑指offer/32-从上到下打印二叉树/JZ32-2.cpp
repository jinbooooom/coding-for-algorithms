/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
            1
          /   \
        2      3
      /  \      \
    4     5      7

输出：[[1], [2, 3], [4, 5, 7]]
*/

/**
把每一层节点都存到容器中
*/

class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> vec2d; // 每一层都存到一个 vector 容器中
        if (pRoot == nullptr)
            return vec2d;

        vector<int> vec; // 存 Node 里的值
        // C++11 中 vector 可以像数组一样用花括号初始化，且等于号可以省。
        vector<TreeNode *> vecNode{pRoot};
        while (!vecNode.empty())
        {
            vector<TreeNode *> thisLayer(vecNode); // 存 Node
            for (int i = 0; i < thisLayer.size(); ++i)
            {
                vec.push_back(thisLayer[i]->val);
            }
            vec2d.push_back(vec);
            vec.clear();
            vecNode.clear();
            for (int i = 0; i < thisLayer.size(); ++i)
            {
                if (thisLayer[i]->left != nullptr)
                    vecNode.push_back(thisLayer[i]->left);
                if (thisLayer[i]->right != nullptr)
                    vecNode.push_back(thisLayer[i]->right);
            }
            thisLayer.clear();
        }
        return vec2d;
    }
};