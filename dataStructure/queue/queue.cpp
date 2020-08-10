#include <iostream>
#include <cassert>

using namespace std;

/*
队列的设计：
该队列为链式队列，无表头结点。
队头指针 front 指向链表的第一个结点（不是表头），尾指针指向链表的尾结点，
从链表尾部入队，链表头部出队。

如图 ./queue.jpg 所示
*/

const bool show = true;					// 是否在每次操作后显示相关信息

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
} Node;


class Queue
{
private:
	Node *rear = nullptr;
	Node *front = nullptr;

public:
	Queue() = default;
	Queue(int value);
	~Queue();
	bool empty() const;					// 队列是否为空
	unsigned int length() const;		// 队列的长度
	int getFront() const;				// 返回队首元素
	int getBack() const;				// 返回队尾元素
	void push(int value);				// 入队
	int pop();							// 出队
	void clear();						// 清空队内数据（front 和 rear 指针还在，数据没有了）
	void traverseQueue() const;			// 遍历队列并打印
};

Queue::Queue(int value)
{
	Node *node = new Node(value);
	this->front = node;
	this->rear = node;
}

Queue::~Queue()
{
	if (show) printf("call ~Queue()\n");
	this->clear();
	delete[] front;
	delete[] rear;
}

bool Queue::empty() const
{
	return rear == nullptr;
}

unsigned int Queue::length() const
{
	if (empty())
		return 0;

	unsigned int cnt = 0;
	Node *p = front;
	while (p)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}

int Queue::getFront() const
{
	assert(front);
	return front->data;
}

int Queue::getBack() const
{
	assert(rear);
	return rear->data;
}

void Queue::push(int value)  // 队尾入队
{
	if (show) printf("call push(%d)\n", value);

	Node* pNode = new Node(value);
	if (empty())
	{
		// Queue(value);	// 注释掉下面三行，调用构造函数，push() 函数不会在队尾添加元素。
							// 因为在成员函数中调用构造函数，只能产生一个无名对象，并不会对原有对象的成员值产生影响。
		
		Node *node = new Node(value);
		front = node;
		rear = node;
		
	}
	else
	{
		rear->next = pNode;
		rear = pNode;
	}
	if (show) traverseQueue();
}

int Queue::pop()  // 队头出队
{
	if (show) printf("call pop():");

	if (empty())
	{
		cerr << "队列为空，无法出队" << endl;
		exit(-1);
	}

	Node *pToBeDelete = front;		// 旧队头指向的结点要出队
	int popData = front->data;		// 存储出队结点的值
	front = front->next;			// 新队头
	delete[] pToBeDelete;			// 删除旧队头指向的结点
	pToBeDelete = nullptr;
	if (front == nullptr)			// 当队列只有一个元素的时候，删除了该唯一元素，front 为空，此时也应该把 rear 置空
	{
		rear = nullptr;
	}
	if (show) cout << popData << endl;
	if (show) traverseQueue();

	return popData;
}

void Queue::traverseQueue() const
{
	if (empty())
	{
		cout << "Queue is empty." << endl;
		return;
	}
	Node *p = front;
	cout << "队头 ";
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "队尾" << endl;
}

void Queue::clear()
{
	if (show) printf("call clear()\n");

	Node *pToBeDelete = nullptr;
	while (front)
	{
		pToBeDelete = front;
		front = front->next;
		delete[] pToBeDelete;
	}
	rear = nullptr;
}

int main()
{
	Queue myqueue;
	cout << (myqueue.empty() ? "empty." : "isn't empty.") << endl;
	myqueue.push(2);
	cout << (myqueue.empty() ? "empty." : "isn't empty.") << endl;
	myqueue.push(5);
	myqueue.push(6);
	myqueue.push(7);
	myqueue.push(8);
	printf("myqueue.getFront() = %d, myqueue.getBack() = %d\n", myqueue.getFront(), myqueue.getBack());
	myqueue.pop();
	myqueue.clear();
	cout << (myqueue.empty() ? "empty." : "isn't empty.") << endl;
	myqueue.push(5);
	myqueue.push(99);
	cout << "length:" << myqueue.length() << endl;

}

/*
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/queue$ g++ queue.cpp -o queue.o -std=c++11
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/queue$ ./queue.o
empty.
call push(2)
队头 2 队尾
isn't empty.
call push(5)
队头 2 5 队尾
call push(6)
队头 2 5 6 队尾
call push(7)
队头 2 5 6 7 队尾
call push(8)
队头 2 5 6 7 8 队尾
myqueue.getFront() = 2, myqueue.getBack() = 8
call pop():2
队头 5 6 7 8 队尾
call clear()
empty.
call push(5)
队头 5 队尾
call push(99)
队头 5 99 队尾
length:2
call ~Queue()
call clear()
*/