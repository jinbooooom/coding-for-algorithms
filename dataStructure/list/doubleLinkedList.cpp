#include <iostream>
#include <vector>

using namespace std;

/*
链表的设计：
带表头结点的双向链表
该程序在单链表 linkedList.cpp 的基础上修改一些功能

一些注意事项：
索引都是从 0 开始
*/

const bool show = true;					// 是否在每次操作后显示相关信息

typedef struct Node
{
	int data;
    Node *prior;
	Node *next;
	Node(int v = 0, Node *pr = nullptr, Node *pn = nullptr) : data(v), prior(pr), next(pn) {};
} Node;

class DoubleLinkList
{
private:
	Node *head = nullptr;

public:
	DoubleLinkList();
	DoubleLinkList(vector<int>& vec);	// 使用 vector 初始化双向链表 
	~DoubleLinkList();
	void push_back(int value);			// 链表尾部添加元素
	void insert(int value, int pos);	// 在 pos 位置插入数据 value
	void deleteNode(int pos);			// 删除指定位置的结点
	void clear();						// 清除链表（只留下头节点）
	int length();		                // 获取链表的长度
	int getElem(int i);					// 获取链表中索引为 i 的节点的数据
	void traverseList();				// 从前到后遍历链表并打印
    void traverseListFromBackToFront(); // 从后到前遍历链表并打印，用来测试调用成员函数后，操作是否正确
	Node* gethead() { return head; }	// 获取头节点
};


DoubleLinkList::DoubleLinkList()
{
	head = new Node();

	// if (show) traverseList();
}

DoubleLinkList::DoubleLinkList(vector<int>& vec)
{
	if (show) cout << "使用 vector 初始化 list" << endl;

	head = new Node(0);
	for (int i = 0; i < vec.size(); ++i)
	{
		this->push_back((vec)[i]);
	}

	// if (show) traverseList();
}

DoubleLinkList::~DoubleLinkList()
{
	if (show) cout << "call ~List()" << endl; 
	this->clear();						// delete[] 掉除头结点的结点
	delete[] head;
	head = nullptr;
}

void DoubleLinkList::push_back(int value)
{
	if (show) printf("call push_back(%d)\n", value);
	
	Node *node = new Node(value);
	Node *p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = node;
    node->prior = p;
	
	if (show) traverseList();
}

void DoubleLinkList::insert(int pos, int value)
{
	if (show) printf("call insert(%d, %d)\n", pos, value);

	if (pos < 0)
	{
		cout << "插入失败，插入的位置应该大于等于零" << endl;
		return;
	}
	else if (pos >= length())		// 如果插入的位置比链表长度都大，直接插入在链表尾部
	{
		printf("插入的位置(%d)大于链表的长度(%d)，直接插在链表的尾部\n", pos, length());
        push_back(value);
		return;
	}

	Node *p = head;
	int index = 0;	// 第一个结点的索引为 0
	while (p->next)
	{
		if (index == pos)
		{
			Node *node = new Node(value);
			node->next = p->next;
            node->prior = p;
			p->next->prior = node;
            p->next = node;
			break;
		}
		p = p->next;
		++index;
	}
	
	if (show) traverseList(), traverseListFromBackToFront();
}

void DoubleLinkList::deleteNode(int pos)  // pos 索引
{
	if (show) printf("call deleteNode(%d)\n", pos);

	if (pos < 0 || pos >= length())
	{
		cout << "待删数据不在链表中" << endl;
		return;
	}

	Node *p = head->next;
	int cnt = 0;
	while (p)
	{
		if (cnt == pos)
		{
			p->prior->next = p->next;
            p->next->prior = p->prior;
			delete[] p;
			p = nullptr;
			break;
		}
		p = p->next;
		++cnt;
	}
	
	if (show) traverseList(), traverseListFromBackToFront();
}

void DoubleLinkList::clear()
{
	if (show) cout << "call clear()" << endl;

	Node *p = head->next;
	Node *pNode = nullptr;
	while (p)
	{
		pNode = p;
		p = p->next;
		delete[] pNode;
		pNode = nullptr;
	}
	head->next = nullptr;
	
	if (show) traverseList();
}

int DoubleLinkList::length()
{
	int cnt = 0;
	Node *p = head->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	// if (show) cout << "length: " << cnt << endl;
	return cnt;
}

int DoubleLinkList::getElem(int pos)		// 索引
{
	if (show) printf("call getElem(%d)", pos);
	
	Node *p = head->next;
	int cur = 0;
	while (p && cur < pos)
	{
		p = p->next;
		++cur;
	}
	
	if (p)
	{
		if (show) printf(": %d\n", p->data);
		return p->data;
	}
	else
	{
		printf("\ngetElem(%d) failed!\n", pos);
		exit(-1);
	}
	
}

void DoubleLinkList::traverseList()
{
	Node *p = head->next;
	while (p)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << "tail" << endl;
}

void DoubleLinkList::traverseListFromBackToFront()
{
    Node *p = head;
    while (p->next)
        p = p->next;
    while (p->prior)
    {
        cout << p->data << " => ";
        p = p->prior;
    }
    cout << "head" << endl;
}

int main()
{
	vector<int> vec {11, 55, 99};
	DoubleLinkList mylist(vec);
	mylist.push_back(9);
	mylist.insert(-1, -3);
	mylist.insert(1, -1);
	mylist.insert(0, 99);
	mylist.insert(100, 5);
    mylist.length();
	mylist.getElem(3);
	mylist.getElem(0);
	// mylist.getElem(100);
	
	mylist.deleteNode(0);
	mylist.deleteNode(2);
	mylist.deleteNode(2);
	mylist.deleteNode(2);
    mylist.length();
	mylist.push_back(12);

	// 退出 main 后执行析构函数
}