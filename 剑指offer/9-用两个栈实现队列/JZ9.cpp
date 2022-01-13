/*
用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。 队列中的元素为 int 类型。
*/

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int data = stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
        // 将 stack1 里的数据放入栈 stack2 后，stack2还是空的，
        // 说明 stack1 本身就是空的，此时就不能出队了,应该报错
        if (stack2.empty())
            cout << "queue is empty" << endl;
        int data = stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1; // 队尾，进队
    stack<int> stack2; // 队头，出队
};
