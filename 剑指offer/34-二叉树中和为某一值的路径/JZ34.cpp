/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

            10
          /   \
        5      12
      /  \
    4     7

如找和为 22 的路径，则输出：
[[10, 5, 7], [10, 12]]
如找和（即期望值）为 15 的路径，则输出 [[]]，
虽然从 10->5 是一个路径，但不是题目中描述的从根节点到叶子节点的路径
*/

/**
 * 提示：
 * 递归。判断左右子树中是否存在路径和为期望值减去当前节点值的路径。
*/

class Solution
{
public:
    vector<vector<int>> vec2d;
    vector<int> vec;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
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