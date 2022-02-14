/**
题目：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
            1
          /   \
        2      3
      /  \      \
    4     5      7

输出：[1, 2, 3, 4, 5, 7]
*/

/**
提示：使用队列存储节点。
根节点先入队，找到队头元素的左右孩子（如果有的话）入队，再使队头元素出队，
此时会有新的队头元素，再找新队头的左右孩子入队，再使新队头出队。
如此反复，直至出队操作使队列再次为空
*/
class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> vec;
        if (root == nullptr)
            return vec;

        queue<TreeNode *> queueNode;
        queueNode.push(root);

        while (!queueNode.empty())
        {
            TreeNode *pNode = queueNode.front();
            queueNode.pop();
            vec.push_back(pNode->val);
            if (pNode->left)
                queueNode.push(pNode->left);
            if (pNode->right)
                queueNode.push(pNode->right);
        }
        return vec;
    }
};