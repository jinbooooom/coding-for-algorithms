#include <iostream>
#include <cassert>

using namespace std;

/*
该队列为链式队列
*/

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
} Node;


class Queue
{
private:
	Node *rear;
	Node *front;

public:
	Queue();
	~Queue();
	bool empty() const;					// 队列是否为空
	int size() const;					// 队列含有的元素数目
	int getFront();						// 返回队首元素
	int getBack();						// 返回队尾元素
	void push(int value);				// 入队
	void pop();							// 出队
	void traverseQueue();				// 遍历链表并打印
};

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}

Queue::~Queue()
{
	;
}

bool Queue::empty() const
{
	return rear == nullptr;
}

int Queue::size() const
{
	if (empty())
		return 0;
	int cnt = 0;
	Node *p = front->next;
	while (p)
	{
		cnt++;
		if (p = rear->next)
			break;
		p = p->next;
	}
	return cnt;
}

int Queue::getFront()
{
	assert(front);
	return front->data;
}

int Queue::getBack()
{
	assert(rear);
	return rear->data;
}

void Queue::push(int value)  // 队尾入队
{
	Node* pNode = new Node(value);
	if (empty())
	{
		front = pNode;
		rear = pNode;
	}
	else
	{
		rear->next = pNode;
		rear = pNode;
	}
	traverseQueue();
}

void Queue::pop()  // 队头出队
{
	if (empty())
	{
		cout << "队列为空，无法出队" << endl;
		return;
	}
	Node* p = front;  // 旧队头
	front = front->next;  // 新队头
	delete[] p; //删除旧队头
	p = nullptr;
	if (front == nullptr) // 当队列只有一个元素的时候，删除了该唯一元素，front 为空，此时也应该把 rear 置空
	{
		rear = nullptr;
	}
	traverseQueue();
}

void Queue::traverseQueue()
{
	if (empty())
	{
		cout << "Queue is empty." << endl;
		return;
	}
	Node* p = front;
	while (p)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << "nullptr" << endl;
}

int main()
{
	Queue q;
	cout << (q.empty() ? "empty." : "isn't empty.") << endl;
	q.push(2);
	cout << (q.empty() ? "empty." : "isn't empty.") << endl;
	q.push(5);
	q.push(6);
	printf("q.getFront() = %d, q.getBack() = %d\n", q.getFront(), q.getBack());
	q.pop();
	q.pop();
	q.pop();
	q.pop();


	system("pause");
}