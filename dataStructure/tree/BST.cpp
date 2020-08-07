#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/*
����������(Binary Sort Tree, BST)
������һ�ÿ�����
�����Ǿ����������ʵĶ�������
��������������Ϊ�գ��������������еĽ���ֵ��С�����ĸ�����ֵ��
��������������Ϊ�գ��������������еĽ���ֵ���������ĸ�����ֵ��
������������Ҳ���Ƕ�����������
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
	void insertNode(int value);					// ��������
	void deleteNode(Node* node, int value);				// ɾ������
	Node* deleteNodeSuper(Node* node, int value);			// ɾ�����ݵ��Ż�
	Node* searchNode(Node* node, int value);			// ����ֵΪ value �Ľ��
	void preOrder(Node* node);					// ǰ�����
	void preOrderUnRec(Node* node);				// ǰ������ǵݹ�
	void inOrder(Node* node);					// �������
	void inOrderUnRec(Node* node);				// ��������ǵݹ�
	void posOrder(Node* node);					// �������
	void posOrderUnRec(Node* node);				// ��������ǵݹ�
	int size();							// ������Ŀ
	int sizeOfLeaf();						// Ҷ�ӽ�����Ŀ
	int depth();						// �����������
	Node* getRoot() { return root; }					// ��ȡ���ڵ�
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
�����������Ĳ��룬�ض��ǲ�����ĳ��Ҷ�ӽ��֮��
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
		pLeaf = p;  // �����������Ĳ��룬�ض��ǲ�����ĳ��Ҷ�ӽ��֮��
		if (value > p->data)
			p = p->right;
		else if (value < p->data)
			p = p->left;
		else // ���ʱ�������� 
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
	Node* par = node;  // par��Ҫɾ���Ľ��ĸ��ڵ�
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
		cout << "û���ҵ� value ��Ӧ�Ľ�㣬ɾ��ʧ�ܣ�" << endl;
		return;
	}
	// Ҫɾ���Ľ����Ҷ�ӽ�㣬ֱ��ɾ��
	if (p->left == nullptr && p->right == nullptr)
	{
		par->left == p ? par->left = nullptr : par->right = nullptr;
		delete[] p;
		p = nullptr;
	}
	// Ҫɾ���Ľ�����ҽ�㣬�øý����ҽ����Ϊ���ڵ�ĺ��ӣ���ɾ���ý��
	else if (p->left == nullptr)
	{
		par->left == p ? par->left = p->right : par->right = p->right;
		delete[] p;
		p = nullptr;
	}
	// Ҫɾ���Ľ�������㣬�øý�����ڵ���Ϊ���ڵ�ĺ��ӣ���ɾ���ý��
	else if (p->right == nullptr)
	{
		par->left == p ? par->left = p->left : par->right = p->left;
		delete[] p;
		p = nullptr;
	}
	// Ҫɾ���Ľ�� p ���������ӽ�㣬��ʱ���� p->right Ϊ�����ɵ��������ҵ�һ����С���� cur->data��ȡ�� p->data��
	// �ٶ��� p->right Ϊ�����ɵ�����ִ��ɾ�� cur->data ����
	else
	{
		Node* cur = p->right;
		while (cur->left)
			cur = cur->left;
		p->data = cur->data;
		deleteNode(p->right, p->data);
	}
}

// ����� void deleteNode(Node*, int) д�ĺ��߳�������Ҳ�����ã�����ο� Node* deleteNodeSuper(Node*, int) 
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
ʹ��һ��ջ���洢��ʱ��㡣
�� p �ǿգ���ӡ�ýڵ�ֵ�����Ӹýڵ���ҽ����ջ��������������
���������������󣬴�ʱ p Ϊ��(Ҷ�ӽ�������Ϊ��)��
��ջ�ǿգ�˵������һЩ�ҽڵ�û�б�������ջ��Ԫ�ظ��� p
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
ʹ��һ��ջ���洢��ʱ���
�Ƚ����ڵ���ջ����������������ջ����������������ȡջ��Ԫ�أ���ջ��Ԫ�ؼ�Ϊ�����㣬��ӡ������ջ��
�ٽ��ý����ҽ���ظ���������
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
ʹ��������ʱջ s1, s2,
�Ƚ����ڵ���ջ s1��
Ȼ��ȡ��ջ��Ԫ�� p����ջ s2, ��ջ s1���ٰѾɵ�ջ��Ԫ�� p �����Һ��ӣ�����еĻ�����ջ s1
*/
void BST::posOrderUnRec(Node* node)
{
	if (node == nullptr)
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

void sizeCore(Node* node, int& cnt)  // ����ṹ�������������ֻ������ͳ�ƽ������
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
	if (find) cout << "�ҵ�5" << endl; else cout << "û���ҵ�5" << endl;
	find = tree.searchNode(root, 99);
	if (find) cout << "�ҵ�99" << endl; else cout << "û���ҵ�99" << endl;
	cout << "depth:" << tree.depth() << endl;

	tree.deleteNode(root, 5);
	cout << "\nɾ�� 5 ������������";
	tree.inOrder(root);
	tree.deleteNode(root, 11);
	cout << "\nɾ�� 11 ������������";
	tree.inOrder(root);
	tree.deleteNode(root, 6);
	cout << "\nɾ�� 6 ������������";
	tree.inOrder(root);

	tree.deleteNodeSuper(root, 8);
	cout << "\nɾ�� 8 ������������";
	tree.inOrder(root);
	tree.deleteNodeSuper(root, 16);
	cout << "\nɾ�� 16 ������������";
	tree.inOrder(root);

	// system("pause");
}