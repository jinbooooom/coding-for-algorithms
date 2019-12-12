class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vec2d;
            if (pRoot == nullptr)
                return vec2d;

            vector<int> vec;
            // C++11 中 vector 可以像数组一样用花括号初始化，且等于号可以省。
            vector<TreeNode*> vecNode {pRoot};
            while (!vecNode.empty())
            {
                vector<TreeNode*> thisLayer(vecNode);
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