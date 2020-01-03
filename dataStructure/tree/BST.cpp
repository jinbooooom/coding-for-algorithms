#include <iostream>
#include <stack>
#include <cassert>

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
	Node(int v = 0) : data(v), left(nullptr), right(nullptr) {};
} Node;


class BST
{
private:
	Node *root;

public:
	BST();
	BST(int arr[], int n);
	~BST();
	void insertNode(int value);							// 插入数据
	void deleteNode(Node* node, int value);				// 删除数据
	Node* deleteNodeSuper(Node* node, int value);		// 删除数据的优化
	Node* searchNode(Node* node, int value);			// 查找值为 value 的结点
	void preOrder(Node* node);							// 前序遍历
	void preOrderUnRec(Node* node);						// 前序遍历非递归
	void inOrder(Node* node);							// 中序遍历
	void inOrderUnRec(Node* node);						// 中序遍历非递归
	void posOrder(Node* node);							// 后序遍历
	void posOrderUnRec(Node* node);						// 后序遍历非递归
	int size();											// 求结点数目
	int sizeOfLeaf();									// 叶子结点的数目
	int depth();										// 二叉树的深度
	Node* getRoot() { return root; }					// 获取根节点
};

BST::BST()
{
	root = nullptr;
}

BST::BST(int arr[], int n)
{
	root = new Node(arr[0]);
	for (int i = 1; i < n; ++i)
		insertNode(arr[i]);
}

BST::~BST()
{
	;
}

/*
二叉排序树的插入，必定是插入在某个叶子结点之下
*/
void BST::insertNode(int value)
{
	Node* p = root, *pLeaf = nullptr;
	if (p == nullptr)
	{
		p = new Node(value);
		return;
	}

	while (p)
	{
		pLeaf = p;  // 二叉排序树的插入，必定是插入在某个叶子结点之下
		if (value > p->data)
			p = p->right;
		else if (value < p->data)
			p = p->left;
		else // 相等时，不操作
			return;
	}

	Node* pNode = new Node(value);
	if (value > pLeaf->data)
		pLeaf->right = pNode;
	else
		pLeaf->left = pNode;
}

void BST::deleteNode(Node* node, int value)
{
	Node* p = node;
	Node* par = node;  // par：要删除的结点的父节点
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
		cout << "没有找到 value 对应的结点，删除失败！" << endl;
		return;
	}
	// 要删除的结点是叶子结点，直接删除
	if (p->left == nullptr && p->right == nullptr)
	{
		par->left == p ? par->left = nullptr : par->right = nullptr;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点有右结点，让该结点的右结点作为父节点的孩子，再删除该结点
	else if (p->left == nullptr)
	{
		par->left == p ? par->left = p->right : par->right = p->right;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点有左结点，让该结点的左节点作为父节点的孩子，再删除该结点
	else if (p->right == nullptr)
	{
		par->left == p ? par->left = p->left : par->right = p->left;
		delete[] p;
		p = nullptr;
	}
	// 要删除的结点 p 含有两个子结点，此时从以 p->right 为根构成的子树中找到一个最小的数 cur->data，取代 p->data，
	// 再对以 p->right 为根构成的子树执行删除 cur->data 操作
	else
	{
		Node* cur = p->right;
		while (cur->left)
			cur = cur->left;
		p->data = cur->data;
		deleteNode(p->right, p->data);
	}
}

// 上面的 deleteNode(Node*, int) 写的很冗长，方法也不够好，建议参考 deleteNodeSuper(Node*, int)
Node* BST::deleteNodeSuper(Node* root, int key)
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

Node* BST::searchNode(Node* node, int value)
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

void BST::preOrder(Node* node)
{
	if (node == nullptr)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

/*
使用一个栈来存储临时结点。
若 p 非空，打印该节点值，添加该节点的右结点入栈，遍历左子树，
当遍历完左子树后，此时 p 为空(叶子结点的左孩子为空)，
若栈非空，说明还有一些右节点没有遍历，将栈顶元素赋给 p
*/
void BST::preOrderUnRec(Node* node)
{
	if (node == nullptr)
		return;
	Node* p = node;
	stack<Node*> s;
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

void BST::inOrder(Node* node)
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
再将该结点的右结点重复上述过程
*/
void BST::inOrderUnRec(Node* node)
{
	if (node == nullptr)
		return;
	Node* p = node;
	stack<Node*> s;
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

void BST::posOrder(Node* node)
{
	if (node == nullptr)
		return;
	posOrder(node->left);
	posOrder(node->right);
	cout << node->data << " ";
}

/*
使用两个临时栈 s1, s2,
先将根节点入栈 s1，
然后取出栈顶元素 p，入栈 s2, 出栈 s1，再把旧的栈顶元素 p 的左右孩子（如果有的话）入栈 s1
*/
void BST::posOrderUnRec(Node* node)
{
	if(node == nullptr)
		return;
	Node* p = node;
	stack<Node*> s1, s2;
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

void sizeCore(Node* node, int& cnt)  // 这个结构很像中序遍历，只不过是统计结点总数
{
	if (node == nullptr)
		return;
	sizeCore(node->left, cnt);
	cnt++;
	sizeCore(node->right, cnt);
}

int BST::size()
{
	if (root == nullptr)
		return 0;
	int cnt = 0;
	sizeCore(root, cnt);
	return cnt;
}

int sizeOfLeafCore(Node* node)
{
	if (node == nullptr)
		return 0;
	else if (node->left == nullptr && node->right == nullptr)
		return 1;
	else
		return sizeOfLeafCore(node->left) + sizeOfLeafCore(node->right);
}

int BST::sizeOfLeaf()
{
	if (root == nullptr)
		return 0;
	return sizeOfLeafCore(root);
}

int depthCore(Node* node)
{
	if (node == nullptr)
		return 0;
	int left_depth = 1 + depthCore(node->left);
	int right_depth = 1 + depthCore(node->right);
	return left_depth >= right_depth ? left_depth : right_depth;
}

int BST::depth()
{
	if (root == nullptr)
		return 0;
	return depthCore(root);
}

int main()
{
	int arr[] = { 12, 6, 8, 4, 5, 12, 8, 16, 13, 11, 9, 7, 20 };
	BST tree(arr, 13);
	Node* root = tree.getRoot();
	cout << "root value:" << root->data << endl;

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
	cout << "size of leaf:" << tree.sizeOfLeaf() << endl;

	Node* find = tree.searchNode(root, 5);
	if (find) cout << "找到5" << endl; else cout << "没有找到5" << endl;
	find = tree.searchNode(root, 99);
	if (find) cout << "找到99" << endl; else cout << "没有找到99" << endl;
	cout << "depth:" << tree.depth() << endl;

	tree.deleteNode(root, 5);
	cout << "\n删除 5 后的中序遍历：";
	tree.inOrder(root);
	tree.deleteNode(root, 11);
	cout << "\n删除 11 后的中序遍历：";
	tree.inOrder(root);
	tree.deleteNode(root, 6);
	cout << "\n删除 6 后的中序遍历：";
	tree.inOrder(root);

	tree.deleteNodeSuper(root, 8);
	cout << "\n删除 8 后的中序遍历：";
	tree.inOrder(root);
	tree.deleteNodeSuper(root, 16);
	cout << "\n删除 16 后的中序遍历：";
	tree.inOrder(root);

	system("pause");
}