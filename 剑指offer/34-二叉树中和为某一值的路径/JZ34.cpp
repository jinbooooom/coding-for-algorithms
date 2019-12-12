class Solution {
public:
    vector<vector<int> > vec2d;
    vector<int> vec;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) //【1】
            return vec2d;
        vec.push_back(root->val);
        // 【2】处：路径指的是从根结点到叶子结点
        if (root->val == expectNumber && root->left == nullptr && root->right == nullptr) //【2】
            vec2d.push_back(vec);
        if (root->left) //【3】
            FindPath(root->left, expectNumber - root->val);
        if (root->right) //【4】
            FindPath(root->right, expectNumber - root->val);
        // 【5】处：假设从根节点到某叶子结点的路径满足条件，那么肯定在【2】处被添加到 vec2d 里的，
        // 显然，【3】【4】处的 if 内是进不去的，此时只要 vec 不为空，就弹出最后面的元素。
        if (!vec.empty()) //【5】
            vec.pop_back();
        return vec2d;
    }
};