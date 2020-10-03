#include<iostream>
#include<stack>//中序遍历时用到栈
#include<queue>//层遍历时用到队列
using namespace std;
typedef char TElemType;//给char取个别名叫做TElemType
class BiTNode
{
private:
	TElemType data;//数据域
	BiTNode* lchild, * rchild;//指针域，分lchild左子树和rchild右子树
public:
	BiTNode()//创建二叉树时，先把左子树和右子树置空
	{
		lchild = NULL;
		rchild = NULL;
	}
	void CreateBiTree(BiTNode*& T)//前序遍历创建二叉树，*&为对指针的引用
	{
		TElemType ch;
		cin.get(ch);
		if (ch == ' ')//若读到这里为空，则制空
		{
			T = NULL;
		}
		else//如果非空，则生成有效二叉树结点
		{
			if (!(T = new BiTNode))//如果生成失败就退出
			{
				cout << "生成失败" << endl;
			}
			T->data = ch;
			CreateBiTree(T->lchild);//按照先序遍历，先生成左子树再生成右子树
			CreateBiTree(T->rchild);
		}
	}
	void Preorder_Traversal(BiTNode*& T)//前序遍历
	{
		if (T != NULL)//只要结点不为空就输出并找其左子树和右子树
		{
			cout << T->data;
			Preorder_Traversal(T->lchild);
			Preorder_Traversal(T->rchild);
		}
	}
	void Inorder_Traversal(BiTNode*& T)//中序遍历非递归算法
	{
		BiTNode* p;//作为一个游动的指针，在接下来的代码中不断地指向栈的顶部
		stack<BiTNode*>s;//建立一个BiTNode*的栈，内部存的都是BiTNode*
		s.push(T);//先把根进栈
		while (!s.empty())//只要栈不空，那就继续循环
		{
			p = s.top();//让p指向栈的头部所指向的二叉树结点
			while (p != NULL)//如果p指向的那个二叉树结点不为空，就继续循环,不停的往栈里入栈左子树
			{
				s.push(p->lchild);//左子树进栈
				p = s.top();//让p指向栈的头部所指向的二叉树结点
			}
			s.pop();//进入这个地方时，肯定有一个NULL进栈了并且成为了栈顶，那就把这个NULL出栈
			if (!s.empty())//如果栈不是空的，就进去
			{
				p = s.top();//让p指向栈的头部所指向的二叉树结点
				cout << p->data;//输出p所指向的二叉树结点的数据域
				s.pop();//输出后就出栈
				s.push(p->rchild);//有刚才的代码可知走到这一步时p指向栈的头部所指向的二叉树结点的左子树遍历完了，该遍历p指向栈的头部所指向的二叉树结点右子树了
			}
		}
	}
	void Postorder_Traversal(BiTNode*& T)//后序遍历
	{
		if (T != NULL)//只要结点不为空就先进入其左子树然后进入右子树最后输出根
		{
			Postorder_Traversal(T->lchild);
			Postorder_Traversal(T->rchild);
			cout << T->data;
		}
	}
	void Traversal_by_layer_by_layer(BiTNode*& T)//层遍历非递归算法
	{
		queue<BiTNode*>q;//创建一个队列
		BiTNode* e;//在接下来的代码中e会不停的指向队列的队首所指向的二叉树结点
		if (T)//如果不是空二叉树就进入
		{
			q.push(T);//先让这个二叉树的根入栈
			while (!q.empty())
			{
				e = q.front();//让e指向队列的队首所指向的二叉树结点
				q.pop();//把队首出队列
				cout << e->data;//把e指向的那个二叉树结点的数据域输出出来
				if (e->lchild != NULL)//如果有左子树就把左子树结点放进队列
				{
					q.push(e->lchild);
				}
				if (e->rchild != NULL)//如果有右子树就把右子树结点放进队列
				{
					q.push(e->rchild);
				}
			}
			cout << endl;
		}
	}
	bool FindNode(BiTNode*& T, TElemType key)//查找节点算法(基于中序遍历非递归算法)
	{
		BiTNode* p;//作为一个游动的指针，在接下来的代码中不断地指向栈的顶部
		stack<BiTNode*>s;//建立一个BiTNode*的栈，内部存的都是BiTNode*
		s.push(T);//先把根进栈
		while (!s.empty())//只要栈不空，那就继续循环
		{
			p = s.top();//让p指向栈的头部所指向的二叉树结点
			while (p != NULL)//如果p指向的那个二叉树结点不为空，就继续循环,不停的往栈里入栈左子树
			{
				s.push(p->lchild);//左子树进栈
				p = s.top();//让p指向栈的头部所指向的二叉树结点
			}
			s.pop();//进入这个地方时，肯定有一个NULL进栈了并且成为了栈顶，那就把这个NULL出栈
			if (!s.empty())//如果栈不是空的，就进去
			{
				p = s.top();//让p指向栈的头部所指向的二叉树结点
				if (p->data == key)//如果这个结点匹配上了咱们要找的那个数据
				{
					return true;//返回true
				}
				s.pop();//输出后就出栈
				s.push(p->rchild);//有刚才的代码可知走到这一步时p指向栈的头部所指向的二叉树结点的左子树遍历完了，该遍历p指向栈的头部所指向的二叉树结点右子树了
			}
		}
		return false;//如果没找到，返回false
	}
	int CountLeaf(BiTNode*& T)//计算叶子节点数(基于中序遍历非递归算法)
	{
		int answer = 0;//用于在后续代码中统计叶子结点个数
		BiTNode* p;//作为一个游动的指针，在接下来的代码中不断地指向栈的顶部
		stack<BiTNode*>s;//建立一个BiTNode*的栈，内部存的都是BiTNode*
		s.push(T);//先把根进栈
		while (!s.empty())//只要栈不空，那就继续循环
		{
			p = s.top();//让p指向栈的头部所指向的二叉树结点
			while (p != NULL)//如果p指向的那个二叉树结点不为空，就继续循环,不停的往栈里入栈左子树
			{
				s.push(p->lchild);//左子树进栈
				p = s.top();//让p指向栈的头部所指向的二叉树结点
			}
			s.pop();//进入这个地方时，肯定有一个NULL进栈了并且成为了栈顶，那就把这个NULL出栈
			if (!s.empty())//如果栈不是空的，就进去
			{
				p = s.top();//让p指向栈的头部所指向的二叉树结点
				if (p->lchild == NULL && p->rchild == NULL)//如果这个结点既没有左子树也没有右子树，那就是叶子结点
				{
					answer++;//统计叶子结点个数
				}
				s.pop();//输出后就出栈
				s.push(p->rchild);//有刚才的代码可知走到这一步时p指向栈的头部所指向的二叉树结点的左子树遍历完了，该遍历p指向栈的头部所指向的二叉树结点右子树了
			}
		}
		return answer;
	}
	int CountLayer(BiTNode*& T)//计算层数(基于层遍历非递归算法)
	{
		int count = 0;//记录层数
		queue<BiTNode*>q;//创建一个队列
		BiTNode* e, * temp;//在接下来的代码中e会不停的指向队列的队首所指向的二叉树结点,temp指向每层二叉树的最后一个结点
		if (T)//如果不是空二叉树就进入
		{
			q.push(T);//先让这个二叉树的根入栈
			temp = q.back(); //先指向第一层最后一个结点，因为第一层只有一个结点，所以相当于temp=T
			while (!q.empty())
			{
				e = q.front();//让e指向队列的队首所指向的二叉树结点
				q.pop();//把队首出队列
				if (e->lchild != NULL)//如果有左子树就把左子树结点放进队列
				{
					q.push(e->lchild);
				}
				if (e->rchild != NULL)//如果有右子树就把右子树结点放进队列
				{
					q.push(e->rchild);
				}
				if (e == temp)
				{
					if (!q.empty())
					{
						temp = q.back();//每遍历完一层，队尾就是这层二叉树结点的最后一个结点，这行代码相当于将temp指向每层二叉树的最后一个结点
					}
					count++;//每遍历完一层，层数加一
				}
			}
		}
		return count;
	}
	void DestoryBiTNode(BiTNode*& T)//析构二叉树(基于后序遍历递归算法一点一点从下到上从左到右一点一点释放结点所占用的内存)
	{
		if (T != NULL)//只要结点不为空就先进入其左子树然后进入右子树最后释放根所占用的空间
		{
			DestoryBiTNode(T->lchild);
			DestoryBiTNode(T->rchild);
			delete[] T;//释放空间
		}
	}
};
int main()
{
	BiTNode* tree;
	cout << "请输入完整的前序遍历，左子树或右子树为空用空格占位：";
	tree->CreateBiTree(tree);
	cout << "先序遍历结果为：";
	tree->Preorder_Traversal(tree);
	cout << endl << "中序遍历结果为：";
	tree->Inorder_Traversal(tree);
	cout << endl << "后序遍历结果为：";
	tree->Postorder_Traversal(tree);
	cout << endl << "层遍历结果为：";
	tree->Traversal_by_layer_by_layer(tree);
	TElemType key;
	cout << "请输入查找的数据：";
	cin >> key;
	if (tree->FindNode(tree, key))
	{
		cout << "节点被查找到！" << endl;
	}
	else
	{
		cout << "节点没有查找到！" << endl;
	}
	cout << "这个二叉树的叶子数为：" << tree->CountLeaf(tree) << endl;
	cout << "这个二叉树的层数为：" << tree->CountLayer(tree) << endl;
	tree->DestoryBiTNode(tree);
	cout << "析构二叉树完毕！" << endl;
	return 0;
}