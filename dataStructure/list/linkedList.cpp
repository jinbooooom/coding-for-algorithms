#include <iostream>
#include <vector>

using namespace std;

/*
链表的设计：
有的链表直接从第一个结点就开始存放数据；
有的链表存在表头结点，即链表的第一个结点用来存放链表的长度之类的数据或者空着不用（本文件方案）；
头节点中不存放数据，只存放指向首节点的指针，
设置头节点的目的是为了方便对链表的操作，如果不设置头节点，而是直接由头指针指向首节点，
这样在对头指针后的节点进行插入删除操作时就会与其他节点进行该操作时有所不同，便要作为一种特殊情况来分析

一些注意事项：
索引都是从 0 开始
*/

const bool show = true;					// 是否在每次操作后显示相关信息

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
} Node;

class List
{
private:
	Node *head = nullptr;

public:
	List();
	List(vector<int>& vec);				// 使用 vector 初始化链表 
	~List();
	void push_back(int value);			// 链表尾部添加元素
	void insert(int value, int pos);	// 在 pos 位置插入数据 value
	void deleteNode(int pos);			// 删除指定位置的结点
	void clear();						// 清除链表（只留下头节点）
	int length();						// 获取链表的长度
	int getElem(int i);					// 获取链表中索引为 i 的节点的数据
	void traverseList();				// 遍历链表并打印
	Node* gethead() { return head; }	// 获取头节点
};


List::List()
{
	head = new Node(0);

	if (show) traverseList();
}

List::List(vector<int>& vec)
{
	if (show) cout << "使用 vector 初始化 list" << endl;

	head = new Node(0);
	for (int i = 0; i < vec.size(); ++i)
	{
		this->push_back((vec)[i]);
	}

	if (show) traverseList();
}

List::~List()
{
	if (show) cout << "call ~List()" << endl; 
	this->clear();						// delete[] 掉除头结点的结点
	delete[] head;
	head = nullptr;
}

void List::push_back(int value)
{
	if (show) printf("call push_back(%d)\n", value);
	
	Node *node = new Node(value);
	Node *p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = node;
	
	if (show) traverseList();
}

void List::insert(int pos, int value)
{
	if (show) printf("call insert(%d, %d)\n", pos, value);

	if (pos < 0)
	{
		cout << "插入失败，插入的位置应该大于等于零" << endl;
		return;
	}
	else if (pos >= length())		// 如果插入的位置比链表长度都大，直接插入在链表尾部
	{
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
			p->next = node;
			break;
		}
		p = p->next;
		++index;
	}
	
	if (show) traverseList();
}

void List::deleteNode(int pos)  // pos 索引
{
	// mainJZ18.cpp 提供了接口为 void deleteNode(ListNode* pListHead, ListNode* pToBeDeleted) 的实现
	if (show) printf("call deleteNode(%d)\n", pos);

	if (pos < 0 || pos >= length())
	{
		cout << "待删数据不在链表中" << endl;
		return;
	}

	Node *p = head;
	Node *pnext = p->next;
	int cnt = 0;
	while (pnext)
	{
		if (cnt == pos)
		{
			p->next = pnext->next;
			delete[] pnext;
			pnext = nullptr;
			break;
		}
		p = pnext;
		pnext = pnext->next;
		++cnt;
	}
	
	if (show) traverseList();
}

void List::clear()
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

int List::length()
{
	int cnt = 0;
	Node *p = head->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	cout << "length: " << cnt << endl;
	return cnt;
}

int List::getElem(int pos)		// 索引
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

void List::traverseList()
{
	Node *p = head->next;
	while (p)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << "nullptr" << endl;
}

int main()
{
	vector<int> vec {11, 55, 99};
	List mylist(vec);
	mylist.push_back(9);
	mylist.insert(-1, -3);
	mylist.insert(1, -1);
	mylist.insert(0, 99);
	mylist.insert(100, 5);
	mylist.getElem(3);
	mylist.getElem(0);
	// mylist.getElem(100);
	
	mylist.deleteNode(0);
	mylist.deleteNode(2);
	mylist.deleteNode(2);
	mylist.deleteNode(2);
	mylist.push_back(12);

	// 退出 main 后执行析构函数
}