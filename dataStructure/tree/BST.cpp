#include <iostream>
#include <stack>

using namespace std;

/*
二叉排序树(Binary Sort Tree, BST)
或者是一棵空树；
或者是具有下列性质的二叉树：
若它的左子树不为空，则左子树上所有的结点的值均小于它的根结点的值；
若它的右子树不为空，则右子树上所有的结点的值均大于它的根结点的值；
它的左右子树也都是二叉排序树。
*/

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int v = 0) : data(v), left(nullptr), right(nullptr){};
} Node;

class BST
{
private:
	Node *root = nullptr;

public:
	BST() = default;
	BST(int value);
	BST(int arr[], int n);
	~BST();
	void insertNode(int value);					   // 插入数据
	void deleteNode(int value);					   // 删除数据
	Node *deleteNodeSuper(Node *node, int value);  // 删除数据的优化
	Node *searchNode(Node *node, int value) const; // 查找值为 value 的结点
	void preOrder(Node *node) const;			   // 前序遍历
	void preOrderUnRec(Node *node) const;		   // 前序遍历非递归
	void inOrder(Node *node) const;				   // 中序遍历
	void inOrderUnRec(Node *node) const;		   // 中序遍历非递归
	void posOrder(Node *node) const;			   // 后序遍历
	void posOrderUnRec(Node *node) const;		   // 后序遍历非递归
	int size() const;							   // 求结点数目
	int sizeOfLeaf() const;						   // 叶子结点的数目
	int depth() const;							   // 二叉树的深度
	Node *getRoot() const { return root; }		   // 获取根节点
};

BST::BST(int value)
{
	root = new Node(value);
}

BST::BST(int arr[], int n)
{
	root = new Node(arr[0]);
	for (int i = 1; i < n; ++i)
		insertNode(arr[i]);
}

void destructorCore(Node *node) // 从叶子结点开始 delete[]
{
	if (node == nullptr)
		return;
	destructorCore(node->left);
	destructorCore(node->right);
	delete[] node;
}

BST::~BST()
{
	cout << "call ~BST()" << endl;
	destructorCore(root);
}

/*
二叉排序树的插入必定是插在某个叶子结点之下
*/
void BST::insertNode(int value)
{
	Node *p = root, *pLeaf = nullptr;
	if (p == nullptr)
	{
		p = new Node(value);
		return;
	}

	while (p)
	{
		pLeaf = p; // 二叉排序树的插入必定是插在某个叶子结点之下
		if (value > p->data)
			p = p->right;
		else if (value < p->data)
			p = p->left;
		else // 相等时，不操作
			return;
	}

	p = new Node(value);
	if (value > pLeaf->data)
		pLeaf->right = p;
	else
		pLeaf->left = p;
}

void BST::deleteNode(int value)
{
	Node *p = root;
	Node *par = root; // par: 要删除的结点的父结点
	while (p)
	{
		if (value > p->data)
		{
			par = p;
			p = p->right;
		}
		else if (value < p->data)
		{
			par = p;
			p = p->left;
		}
		else
			break;
	}
	if (p == nullptr)
	{
		cerr << "没有找到 value 对应的结点，删除失败！" << endl;
		return;
	}
	// 要删除的结点是叶子结点，直接删除
	if (p->left == nullptr && p->right == nullptr)
	{
		par->left == p ? par->left = nullptr : par->right = nullptr;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点只有右结点，没左节点，让该结点的右结点作为父结点的孩子，再删除该结点
	else if (p->left == nullptr)
	{
		par->left == p ? par->left = p->right : par->right = p->right;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点只有左结点，没右节点，让该结点的左结点作为父结点的孩子，再删除该结点
	else if (p->right == nullptr)
	{
		par->left == p ? par->left = p->left : par->right = p->left;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点 p 含有两个子节点，此时从以 p->right 为根构成的子树中找到一个最小的数 cur->data，取代 p->data。
	// 再对以 p->right 为根构成的子树执行删除 cur->data 操作
	else
	{
		Node *cur = p->right;
		Node *parcur = p; // cur 的父结点
		while (cur->left)
		{
			parcur = cur;
			cur = cur->left;
		}
		p->data = cur->data; // 用右子树最左边结点的值覆盖掉要删除的结点，就可以认为要删除的结点 p 被删除
		delete[] cur;
		cur = nullptr;
		parcur->left = nullptr; // 防止野指针
	}
}

// 上面的 void deleteNode(int) 写的很冗长，精炼一些的可以参考 Node *deleteNodeSuper(Node*, int)
Node *BST::deleteNodeSuper(Node *root, int key)
{
	if (!root)
		return root;
	else if (root->data > key)
		root->left = deleteNodeSuper(root->left, key);
	else if (root->data < key)
		root->right = deleteNodeSuper(root->right, key);
	else
	{
		if (root->left == nullptr || root->right == nullptr)
			root = root->left ? root->left : root->right;
		else
		{
			Node *cur = root->right;
			while (cur->left)
				cur = cur->left;
			root->data = cur->data;
			root->right = deleteNodeSuper(root->right, root->data);
		}
	}
	return root;
}

/**
 * 在以 node 为根的 BST 中，查找 value 所在的结点。
*/
Node *BST::searchNode(Node *node, int value) const
{
	Node *p = node;
	if (p == nullptr)
		return nullptr;
	if (value > p->data)
		searchNode(p->right, value);
	else if (value < p->data)
		searchNode(p->left, value);
	else
		return p;
}

void BST::preOrder(Node *node) const
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

/*
使用一个栈来存储临时结点。
若 p 非空，打印该结点值，添加该结点的右结点入栈，遍历左子树，
当遍历完左子树后，此时 p 为空（叶子结点的左孩子为空），
若栈非空，说明还有一些右结点没有遍历，将栈顶元素赋给 p
*/
void BST::preOrderUnRec(Node *node) const
{
	if (node == nullptr)
		return;
	Node *p = node;
	stack<Node *> s;
	while (p || !s.empty())
	{
		while (p)
		{
			cout << p->data << " ";
			s.push(p->right);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
		}
	}
}

void BST::inOrder(Node *node) const
{
	if (node)
	{
		inOrder(node->left);
		cout << node->data << " ";
		inOrder(node->right);
	}
}

/*
使用一个栈来存储临时结点
先将根节点入栈，遍历左子树并入栈，遍历完左子树后，取栈顶元素，此栈顶元素即为最左结点，打印它并出栈，
再对该结点的右结点重复以上过程。
*/
void BST::inOrderUnRec(Node *node) const
{
	if (node == nullptr)
		return;
	Node *p = node;
	stack<Node *> s;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->right;
		}
	}
}

void BST::posOrder(Node *node) const
{
	if (node == nullptr)
		return;
	posOrder(node->left);
	posOrder(node->right);
	cout << node->data << " ";
}

/*
使用两个临时栈 s1 和 s2
先将根节点入栈 s1
然后取出栈顶元素 p，入栈 s2，出栈 s1，再把旧的栈顶元素 p 的左右孩子（如果有的话）入栈 s1
*/
void BST::posOrderUnRec(Node *node) const
{
	if (node == nullptr)
		return;
	Node *p = node;
	stack<Node *> s1, s2;
	s1.push(node);

	while (!s1.empty())
	{
		p = s1.top();
		s1.pop();
		s2.push(p);
		if (p->left)
			s1.push(p->left);
		if (p->right)
			s1.push(p->right);
	}
	while (!s2.empty())
	{
		cout << s2.top()->data << " ";
		s2.pop();
	}
}

void sizeCore(Node *node, int &cnt) // 这个结构很像中序遍历，只不过是统计结点总数
{
	if (node == nullptr)
		return;
	sizeCore(node->left, cnt);
	++cnt;
	sizeCore(node->right, cnt);
}

int BST::size() const
{
	if (root == nullptr)
		return 0;
	int cnt = 0;
	sizeCore(root, cnt);
	return cnt;
}

int sizeOfLeafCore(Node *node)
{
	if (node == nullptr)
		return 0;
	else if (node->left == nullptr && node->right == nullptr)
		return 1;
	else
		return sizeOfLeafCore(node->left) + sizeOfLeafCore(node->right);
}

int BST::sizeOfLeaf() const
{
	if (root == nullptr)
		return 0;
	return sizeOfLeafCore(root);
}

int depthCore(Node *node)
{
	if (node == nullptr)
		return 0;
	int left_depth = 1 + depthCore(node->left);
	int right_depth = 1 + depthCore(node->right);
	return left_depth >= right_depth ? left_depth : right_depth;
}

int BST::depth() const
{
	if (root == nullptr)
		return 0;
	return depthCore(root);
}

int main()
{
	int arr[] = {12, 6, 8, 4, 5, 12, 8, 16, 13, 11, 9, 7, 20};
	BST tree(arr, 13);
	Node *root = tree.getRoot();
	cout << "root value: " << root->data << endl;

	cout << "\npreOrder:     ";
	tree.preOrder(root);
	cout << "\npreOrderUnRec:";
	tree.preOrderUnRec(root);
	cout << "\ninOrder:      ";
	tree.inOrder(root);
	cout << "\ninOrderUnRec: ";
	tree.inOrderUnRec(root);
	cout << "\nposOrder:     ";
	tree.posOrder(root);
	cout << "\nposOrderUnRec:";
	tree.posOrderUnRec(root);

	cout << "\n------------------------\n";
	cout << "size:" << tree.size() << endl;
	cout << "size of leaves:" << tree.sizeOfLeaf() << endl;

	Node *find = tree.searchNode(root, 5);
	if (find)
		cout << "找到 5" << endl;
	else
		cout << "没有找到 5" << endl;
	find = tree.searchNode(root, 99);
	if (find)
		cout << "找到 99" << endl;
	else
		cout << "没有找到 99" << endl;
	cout << "depth:" << tree.depth() << endl;

	tree.deleteNode(5);
	cout << "\n删除 5 后的中序遍历:     ";
	tree.inOrder(root);
	tree.deleteNode(11);
	cout << "\n删除 11 后的中序遍历:    ";
	tree.inOrder(root);
	tree.deleteNode(6);
	cout << "\n删除 6 后的中序遍历:     ";
	tree.inOrder(root);

	tree.deleteNodeSuper(root, 8);
	cout << "\n使用 deleteNodeSuper(Node *, int) 删除 8 后的中序遍历：";
	tree.inOrder(root);
	tree.insertNode(15);
	cout << "\n插入 15 后的中序遍历：";
	tree.inOrder(root);
	cout << endl;
}

/*
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/tree$ g++ BST.cpp -o BST.o -std=c++11
jinbo@fang:~/gitme/coding-for-algorithms/dataStructure/tree$ ./BST.o 
root value: 12

preOrder:     12 6 4 5 8 7 11 9 16 13 20 
preOrderUnRec:12 6 4 5 8 7 11 9 16 13 20 
inOrder:      4 5 6 7 8 9 11 12 13 16 20 
inOrderUnRec: 4 5 6 7 8 9 11 12 13 16 20 
posOrder:     5 4 7 9 11 8 6 13 20 16 12 
posOrderUnRec:5 4 7 9 11 8 6 13 20 16 12 
------------------------
size:11
size of leaves:5
找到 5
没有找到 99
depth:5

删除 5 后的中序遍历:     4 6 7 8 9 11 12 13 16 20 
删除 11 后的中序遍历:    4 6 7 8 9 12 13 16 20 
删除 6 后的中序遍历:     4 7 8 9 12 13 16 20 
使用 deleteNodeSuper(Node *, int) 删除 8 后的中序遍历：4 7 9 12 13 16 20 
插入 15 后的中序遍历：4 7 9 12 13 15 16 20 
call ~BST()
*/
