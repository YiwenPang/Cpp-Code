#include<iostream>
#include<stack>//�������ʱ�õ�ջ
#include<queue>//�����ʱ�õ�����
using namespace std;
typedef char TElemType;//��charȡ����������TElemType
class BiTNode
{
private:
	TElemType data;//������
	BiTNode* lchild, * rchild;//ָ���򣬷�lchild��������rchild������
public:
	BiTNode()//����������ʱ���Ȱ����������������ÿ�
	{
		lchild = NULL;
		rchild = NULL;
	}
	void CreateBiTree(BiTNode*& T)//ǰ�����������������*&Ϊ��ָ�������
	{
		TElemType ch;
		cin.get(ch);
		if (ch == ' ')//����������Ϊ�գ����ƿ�
		{
			T = NULL;
		}
		else//����ǿգ���������Ч���������
		{
			if (!(T = new BiTNode))//�������ʧ�ܾ��˳�
			{
				cout << "����ʧ��" << endl;
			}
			T->data = ch;
			CreateBiTree(T->lchild);//�������������������������������������
			CreateBiTree(T->rchild);
		}
	}
	void Preorder_Traversal(BiTNode*& T)//ǰ�����
	{
		if (T != NULL)//ֻҪ��㲻Ϊ�վ������������������������
		{
			cout << T->data;
			Preorder_Traversal(T->lchild);
			Preorder_Traversal(T->rchild);
		}
	}
	void Inorder_Traversal(BiTNode*& T)
	{
		BiTNode* p;//��Ϊһ���ζ���ָ�룬�ڽ������Ĵ����в��ϵ�ָ��ջ�Ķ���
		stack<BiTNode*>s;//����һ��BiTNode*��ջ���ڲ���Ķ���BiTNode*
		s.push(T);//�ȰѸ���ջ
		while (!s.empty())//ֻҪջ���գ��Ǿͼ���ѭ��
		{
			p = s.top();//��pָ��ջ��ͷ����ָ��Ķ��������
			while (p != NULL)//���pָ����Ǹ���������㲻Ϊ�գ��ͼ���ѭ��,��ͣ����ջ����ջ������
			{
				s.push(p->lchild);//��������ջ
				p = s.top();//��pָ��ջ��ͷ����ָ��Ķ��������
			}
			s.pop();//��������ط�ʱ���϶���һ��NULL��ջ�˲��ҳ�Ϊ��ջ�����ǾͰ����NULL��ջ
			if (!s.empty())//���ջ���ǿյģ��ͽ�ȥ
			{
				p = s.top();//��pָ��ջ��ͷ����ָ��Ķ��������
				cout << p->data;//���p��ָ��Ķ���������������
				s.pop();//�����ͳ�ջ
				s.push(p->rchild);//�иղŵĴ����֪�ߵ���һ��ʱpָ��ջ��ͷ����ָ��Ķ����������������������ˣ��ñ���pָ��ջ��ͷ����ָ��Ķ����������������
			}
		}
	}
	void Postorder_Traversal(BiTNode*& T)
	{
		if (T != NULL)//ֻҪ��㲻Ϊ�վ��Ƚ�����������Ȼ�������������������
		{
			Postorder_Traversal(T->lchild);
			Postorder_Traversal(T->rchild);
			cout << T->data;
		}
	}
	void Traversal_by_layer_by_layer(BiTNode*& T)
	{
		queue<BiTNode*>q;//����һ������
		BiTNode* e;////�ڽ������Ĵ�����e�᲻ͣ��ָ����еĶ�����ָ��Ķ��������
		if (T)//������ǿն������ͽ���
		{
			q.push(T);//��������������ĸ���ջ
			while (!q.empty())
			{
				e = q.front();//��eָ����еĶ�����ָ��Ķ��������
				q.pop();//�Ѷ��׳�����
				cout << e->data;//��eָ����Ǹ������������������������
				if (e->lchild != NULL)//������������Ͱ����������Ž�����
				{
					q.push(e->lchild);
				}
				if (e->rchild != NULL)//������������Ͱ����������Ž�����
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
	cout << "������������ǰ���������������������Ϊ���ÿո�ռλ��";
	tree->CreateBiTree(tree);
	cout << "����������Ϊ��";
	tree->Preorder_Traversal(tree);
	cout << endl << "����������Ϊ��";
	tree->Inorder_Traversal(tree);
	cout << endl << "����������Ϊ��";
	tree->Postorder_Traversal(tree);
	cout << endl << "��������Ϊ��";
	tree->Traversal_by_layer_by_layer(tree);
	return 0;
}