//��ʵ��
class BinaryTree {
private:
	TNODE* root									//�����
public:
	BinaryTree() { root = NULL; }]				//���캯��
	~BinaryTree() { };							//��������
	void CreateBiTree(char* POS, char* IOS);	//����������
	void ClearBiTree();							//��ն�����
	bool IsEmpty() { return root == NULL; }		//�ж����Ƿ�Ϊ��
	int GetDepth(TNODE* t); 					//�����ĸ߶�
	void Assign(TNODE* e, ElemType value)		//������㸳ֵ
	{
		e->data = value;
	}
};

//˳��洢
#define MAX_TREE_SIZE 100						//�����������ڵ��� 
typedef TElemType SqBiTree[MAX_TREE_SIZE];
typedef struct
{
	int level, order;
}position;					//�ڵ�Ĳ�����������

//��������洢
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;			//�����ӽڵ�
}BiTNode, * BiTree;

//��������洢
typedef struct BiTPNode {
	TElemType data;
	struct BiTPNode* parent, * lchild, * rchild;//���ڵ㡢�����ӽڵ�
}BiTPNode, * BiPTree;

//�������
void pre_order_traversal(TreeNode* root)
{
	// Do Something with root
	if (root->lchild != NULL)					//������һ��������ǿ�����ȡ������
		pre_order_traversal(root->lchild);
	if (root->rchild != NULL)					//��һ�������Ҳ����ͬ��
		pre_order_traversal(root->rchild);
}

//�������
void in_order_traversal(TreeNode* root)
{
	if (root->lchild != NULL)					//������һ��������ǿ�����ȡ������
		in_order_traversal(root->lchild);
	// Do Something with root
	if (root->rchild != NULL)					//��һ�������Ҳ����ͬ��
		in_order_traversal(root->rchild);
}

//�������
void post_order_traversal(TreeNode* root)
{
	if (root->lchild != NULL)					//������һ��������ǿ�����ȡ������
		post_order_traversal(root->lchild);
	if (root->rchild != NULL)					//��һ�������Ҳ����ͬ��
		post_order_traversal(root->rchild);
	// Do Something with root
}

//�������
void level(TreeNode* node)
{
	Queue* queue = initQueue();
	enQueue(queue, node);
	while (!isQueueEmpty(queue))
	{
		TreeNode* curr = deQueue(queue);		//��ǰ��εĽڵ���ӽ��б�������
		// Do Something with curr
		if (curr->lchild != NULL)
			enQueue(queue, curr->lchild);		//��һ������ӽڵ����
		if (curr->rchild != NULL)
			enQueue(queue, curr->rchild);		//��һ������ӽڵ����
	}
}

//���������
void BinaryTree::OutBT(TNODE* t)				//�������
{
	if (t)
	{
		cout << t->data;
		if (t->LChild != NULL || t->RChild != NULL)
		{
			cout << ��(��;
			OutBT(t->LChild);
			cout << ��, ��;
			if (t->RChild != NULL)
				OutBT(t->RChild);
			cout << ��)��;
		}
	}
}

//�����
int BinaryTree::BTDepth(TNODE* t)				//�������
{
	int depth;
	if (t == NULL) return FALSE;
	if (t->LChild = = NULL && t->RChild = = NULL)
		depth = 1;
	else
	{
		if (BTDepth(t->LChild) > BTDepth(t->RChild))
			depth = 1 + BTDepth(t->lChild);
		else
			depth = 1 + BTDepth(t->rChild);
	}
	return depth;
}

//���
void BinaryTree::ClearBT(TNODE* t)				//�������
{
	if (t)
	{
		ClearBT(t->LChild);
		ClearBT(t->RChild);
		delete t;
		t = NULL;
	}
}