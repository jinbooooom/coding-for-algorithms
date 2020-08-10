#include <iostream>
#include <vector>
using namespace std;

const bool show = true;

/*
栈的设计有两种：
一种是利用一组地址连续的存储单元依次存放自栈低到栈顶的数据，同时设指针 top 指向栈顶元素所在的位置，若栈为空， top = 0。
但缺点是栈在使用过程中，所需要的最大空间的大小很难估计。一个合理的做法是，先为栈分配一个合理的容量，然后在应用过程中，
当栈的空间不够时再逐段扩大。

另一种是用链式实现，链栈的操作易于实现，如本文件所示。
设置链表头为栈顶指针，每次压栈/弹出都在表头操作，时间复杂度 O(1)。
如果压栈/弹出在链表尾部操作，那么删除链表尾部的元素需要知道它的前驱，这样，时间复杂度就是 O(n)。

一些注意事项：
索引都是从 0 开始
*/

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
} Node;

class Stack
{
private:
    // Node *pbase = nullptr;      // 栈底指针
    Node *ptop = nullptr;       // 栈顶指针

public:
    Stack() = default;          // 默认构造函数
    Stack(int value);           // 构造栈并将 value 压栈
    Stack(vector<int>& vec);    // 使用 vector 初始化栈 
    ~Stack();                   // 析构函数
    void push(int value);       // 压栈
    void pop();                 // 弹出
    int top() const;            // 获取栈顶元素
    bool empty() const;         // 判断栈是否为空
    unsigned int length() const;// 获取栈元素的个数
    void clear();               // 清空栈内元素（保留栈顶指针）
    void traverse() const;      // 遍历栈
};

Stack::Stack(int value)
{
    ptop = new Node(value);
}

Stack::Stack(vector<int>& vec)
{
    if (show) printf("使用 vector 初始化栈\n");
    size_t size = vec.size();
    for (size_t i = 0; i < size; ++i)
    {
        this->push(vec[i]);
    }
    if (show) this->traverse();
}

Stack::~Stack()
{
    if (show) printf("call ~Stack()\n");

    this->clear();
    delete[] ptop;
}

void Stack::push(int value)
{
    if (show) printf("call push(%d)\n", value);
    
    if (!empty())       // 栈非空
    {
        Node *node = new Node(value);
        node->next = ptop;
        ptop = node;
    }
    else                // 空栈
    {
        ptop = new Node(value);
    } 

    if (show) traverse();
}

void Stack::pop()
{
    if (show) printf("call pop()\n");

    if (empty())
    {
        cerr << "栈空，弹出失败！" << endl;
    }
    else
    {
        Node *node = ptop;  // 获取被弹出的元素，然后 delete []
        ptop = ptop->next;
        delete[] node;
        node = nullptr;
    }

    if (show) traverse();
}

int Stack::top() const
{
    if (show) printf("call top():");

    if (empty())
    {
        cerr << "栈为空，无法获取栈顶数据" << endl;
        exit(-1);
    }
    else
    {
        if (show) printf("栈顶元素是：%d\n", ptop->data);
        return ptop->data;
    }

    if (show) cout << ptop->data << endl;
}

bool Stack::empty() const
{
    return ptop == nullptr;
} 

unsigned int Stack::length() const
{
    if (empty())
    {
        return 0;
    }
    else
    {
        unsigned cnt = 0;
        Node *p = ptop;
        while (p)
        {
            p = p->next;
            ++cnt;
        }
        return cnt;
    }
} 

void Stack::clear()
{
    if (show) printf("call clear()\n");

    Node *pToBeDelete = nullptr;
    while (ptop)
    {
        pToBeDelete = ptop;
        ptop = ptop->next;
        delete pToBeDelete; 
    }
    pToBeDelete = nullptr;  // 避免野指针
}

void Stack::traverse() const
{
    if (empty()) cout << "空栈" << endl;
    else
    {
        cout << "栈顶 ";
        Node *p = ptop;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "栈底 " << endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> vec {11, 55, 99};
    Stack mystack(vec);
    // Stack mystack(55);
    cout << "length: " << mystack.length() << endl; 
    mystack.pop();
    mystack.clear();
    mystack.traverse();
    cout << "length: " << mystack.length() << endl; 
    mystack.push(5);
    mystack.push(9);
    mystack.top();
}

/*
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/stack$ g++ stack.cpp -o stack.o -std=c++11
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/stack$ ./stack.o
使用 vector 初始化栈
call push(11)
栈顶 11 栈底 
call push(55)
栈顶 55 11 栈底 
call push(99)
栈顶 99 55 11 栈底 
栈顶 99 55 11 栈底 
length: 3
call pop()
栈顶 55 11 栈底 
call clear()
空栈
length: 0
call push(5)
栈顶 5 栈底 
call push(9)
栈顶 9 5 栈底 
call top():栈顶元素是：9
call ~Stack()
call clear()
*/