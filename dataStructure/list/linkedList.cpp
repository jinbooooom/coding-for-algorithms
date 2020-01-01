#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
} Node;


class List
{
private:
	Node *head;
public:
	List();
	~List();
	void append(int value);				// 链表尾部添加元素
	void insert(int value, int pos);	// 在 pos 位置插入数据
	void deleteNode(int pos);			// 删除指定位置的结点
	int length();						// 获取链表的长度
	void printList();					// 打印链表
	Node* gethead() { return head; }
};
List::List()
{
	head = new Node(0);
}

List::~List()
{
	;
}

void List::append(int value)
{
	Node *node = new Node(value);
	Node *p = this->head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = node;
	printList();
}

void List::insert(int value, int pos)
{
	if (pos < 0)
	{
		cout << "插入失败，插入的位置应该大于等于零" << endl;
		return;
	}
	if (pos >= length())
	{
		append(value);
		return;
	}

	Node* p = head;
	int index = 0;	// 第一个结点的索引为 0
	while (p)
	{
		if (index == pos)
		{
			Node *node = new Node(value);
			node->next = p->next;
			p->next = node;
			break;
		}
		p = p->next;
		index++;
	}
	printList();
}


void List::deleteNode(int pos)  // pos 索引
{
	// 更好的方法可以参考 mainJZ18.cpp
	if (pos < 0 || pos > length() - 1)
	{
		cout << "待删数据不在链表中" << endl;
		return;
	}
	/*
	else if (length() == 1) // 不满足上面 if 的条件，但链表长度又是 1，那删除的只会是第一个节点了
	{
		Node *pDelete = head->next;
		head->next = nullptr;
		delete pDelete;
		pDelete = nullptr;
	}
	*/
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
		cnt++;
	}
	printList();
}

int List::length()
{
	int cnt = 0;
	Node* p = head->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	// cout << "length:" << cnt << endl;
	return cnt;
}

void List::printList()
{
	Node *p = head->next;
	while (p)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << "nullptr" << endl;
}

Node* deleteDuplication(Node* pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)  // 链表为空或者只有一个节点
		return pHead;
	Node* pNext = pHead->next;
	if (pHead->data != pNext->data)
	{
		pHead->next = deleteDuplication(pNext);
		return pHead;
	}
	while (pHead->data == pNext->data && pNext != nullptr)
	{
		pNext = pNext->next;
	}
	if (pHead->data != pNext->data)                     // 说明 pHead 到 pNext 之前的值都重复，应该删去
	{
		pHead = deleteDuplication(pNext);
		return pHead;
	}
	else
	{
		pHead = nullptr;
		return pHead;
	}
}

int main()
{
	List mylist;
	mylist.append(7);
	mylist.append(9);
	cout << mylist.length() << endl;
	mylist.insert(1, 0);
	mylist.insert(10, 3);
	mylist.insert(5, 2);
	mylist.insert(-1, -3);
	mylist.insert(-99, 99);
	mylist.deleteNode(0);
	mylist.deleteNode(2);
	mylist.deleteNode(4);
	mylist.append(7);
	mylist.append(7);
	mylist.append(8);
	mylist.append(8);
	mylist.append(9);
	deleteDuplication(mylist.gethead());
	mylist.printList();
	mylist.deleteNode(1);
	mylist.deleteNode(1);
	mylist.deleteNode(1);
	mylist.deleteNode(1);
	cout << "---" << endl;
	mylist.deleteNode(1);
	mylist.deleteNode(0);


	system("pause");
}