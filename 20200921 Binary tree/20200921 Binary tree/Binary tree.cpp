/*
大家好，咱们马上就要进行蓝桥杯比赛了，在这个时候我会在群里发一些代码，大家可以进行复习，主要关于数据的结构和题目的描述
本次是对二叉树进行解释和对代码的解析
需要知道的知识有：形参和实参，函数，类与对象，指针
大家不懂的地方可以自学
*/
#include<iostream>
using namespace std;
typedef char TElemType;//重新定义char为TElemType
class BiTNode
{
private:
	TElemType data;//数据域
	BiTNode* lchild, * rchild;//左子树和右子树
public:
	BiTNode()//参数为空的构造函数，把左子树和右子树置空
	{
		lchild = NULL;
		rchild = NULL;
	}
	BiTNode(TElemType d,BiTNode *lc,BiTNode *rc)//参数不为空的构造函数，写入数据域和左右子树
	{
		data = d;
		lchild = lc;
		rchild = rc;
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
	void DLR(BiTNode*& T)//先序遍历，先遍历根，再遍历左子树，最后遍历右子树
	{
		if (T != NULL)//如果是空子树就不要输出啦
		{
			cout << T->data;//先遍历根，把根的数据输出
			DLR(T->lchild);//用递归的办法先遍历左子树
			DLR(T->rchild);//同样也是递归，遍历完左子树遍历右子树
		}
	}
	void LDR(BiTNode*& T)//中序遍历，先遍历左子树，再遍历根，最后遍历右子树
	{
		if (T != NULL)//如果是空子树就不要输出啦
		{
			LDR(T->lchild);//用递归的办法先遍历左子树
			cout << T->data;//遍历完左子树遍历根，把根的数据输出
			LDR(T->rchild);//同样也是递归，遍历完根遍历右子树
		}
	}
	void LRD(BiTNode*& T)//后序遍历，先遍历左子树，再遍历右子树，最后遍历根
	{
		if (T != NULL)//如果是空子树就不要输出啦
		{
			LRD(T->lchild);//用递归的办法先遍历左子树
			LRD(T->rchild);//同样也是递归，遍历完左子树遍历右子树
			cout << T->data;//最后遍历根，把根的数据输出
		}
	}
};
int main()
{
	BiTNode* tree;//先创建一个二叉树的总根
	cout << "请输入完整的前序遍历，左子树或右子树为空用空格占位：";
	tree->CreateBiTree(tree);//开始一个一个读取cin.get()里输入的内容
	cout << "先序遍历结果为：";
	tree->DLR(tree);
	cout << endl << "中序遍历结果为：";
	tree->LDR(tree);
	cout << endl << "后序遍历结果为：";
	tree->LRD(tree);
	return 0;
}