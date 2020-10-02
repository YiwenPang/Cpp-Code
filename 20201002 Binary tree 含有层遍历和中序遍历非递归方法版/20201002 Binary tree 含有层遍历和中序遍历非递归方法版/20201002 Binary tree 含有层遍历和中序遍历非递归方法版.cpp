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
	void Inorder_Traversal(BiTNode*& T)
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
	void Postorder_Traversal(BiTNode*& T)
	{
		if (T != NULL)//只要结点不为空就先进入其左子树然后进入右子树最后输出根
		{
			Postorder_Traversal(T->lchild);
			Postorder_Traversal(T->rchild);
			cout << T->data;
		}
	}
	void Traversal_by_layer_by_layer(BiTNode*& T)
	{
		queue<BiTNode*>q;//创建一个队列
		BiTNode* e;////在接下来的代码中e会不停的指向队列的队首所指向的二叉树结点
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
	return 0;
}