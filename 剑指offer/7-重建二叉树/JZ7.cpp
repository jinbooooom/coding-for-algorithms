
/**
 * 题目：
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
提示：
知道前序遍历 pre = [1,2,4,7,3,5,6,8]，则根节点的值必然是 pre[0]，
由于中序遍历会以根节点把树分成左右两部分，所以找到 pre[0] 在中序遍历列表中的位置（设为 p），
就可以以 p 为分界线分别找到左右子树的前序中序序列。

:param pre: 前序遍历序列
:param tin: 中序遍历序列
:return: 树根节点
*/
class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
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