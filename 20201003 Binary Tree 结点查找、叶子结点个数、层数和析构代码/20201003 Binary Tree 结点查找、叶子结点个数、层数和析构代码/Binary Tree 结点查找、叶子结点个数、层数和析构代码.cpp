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
	void Inorder_Traversal(BiTNode*& T)//��������ǵݹ��㷨
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
	void Postorder_Traversal(BiTNode*& T)//�������
	{
		if (T != NULL)//ֻҪ��㲻Ϊ�վ��Ƚ�����������Ȼ�������������������
		{
			Postorder_Traversal(T->lchild);
			Postorder_Traversal(T->rchild);
			cout << T->data;
		}
	}
	void Traversal_by_layer_by_layer(BiTNode*& T)//������ǵݹ��㷨
	{
		queue<BiTNode*>q;//����һ������
		BiTNode* e;//�ڽ������Ĵ�����e�᲻ͣ��ָ����еĶ�����ָ��Ķ��������
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
	bool FindNode(BiTNode*& T, TElemType key)//���ҽڵ��㷨(������������ǵݹ��㷨)
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
				if (p->data == key)//���������ƥ����������Ҫ�ҵ��Ǹ�����
				{
					return true;//����true
				}
				s.pop();//�����ͳ�ջ
				s.push(p->rchild);//�иղŵĴ����֪�ߵ���һ��ʱpָ��ջ��ͷ����ָ��Ķ����������������������ˣ��ñ���pָ��ջ��ͷ����ָ��Ķ����������������
			}
		}
		return false;//���û�ҵ�������false
	}
	int CountLeaf(BiTNode*& T)//����Ҷ�ӽڵ���(������������ǵݹ��㷨)
	{
		int answer = 0;//�����ں���������ͳ��Ҷ�ӽ�����
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
				if (p->lchild == NULL && p->rchild == NULL)//����������û��������Ҳû�����������Ǿ���Ҷ�ӽ��
				{
					answer++;//ͳ��Ҷ�ӽ�����
				}
				s.pop();//�����ͳ�ջ
				s.push(p->rchild);//�иղŵĴ����֪�ߵ���һ��ʱpָ��ջ��ͷ����ָ��Ķ����������������������ˣ��ñ���pָ��ջ��ͷ����ָ��Ķ����������������
			}
		}
		return answer;
	}
	int CountLayer(BiTNode*& T)//�������(���ڲ�����ǵݹ��㷨)
	{
		int count = 0;//��¼����
		queue<BiTNode*>q;//����һ������
		BiTNode* e, * temp;//�ڽ������Ĵ�����e�᲻ͣ��ָ����еĶ�����ָ��Ķ��������,tempָ��ÿ������������һ�����
		if (T)//������ǿն������ͽ���
		{
			q.push(T);//��������������ĸ���ջ
			temp = q.back(); //��ָ���һ�����һ����㣬��Ϊ��һ��ֻ��һ����㣬�����൱��temp=T
			while (!q.empty())
			{
				e = q.front();//��eָ����еĶ�����ָ��Ķ��������
				q.pop();//�Ѷ��׳�����
				if (e->lchild != NULL)//������������Ͱ����������Ž�����
				{
					q.push(e->lchild);
				}
				if (e->rchild != NULL)//������������Ͱ����������Ž�����
				{
					q.push(e->rchild);
				}
				if (e == temp)
				{
					if (!q.empty())
					{
						temp = q.back();//ÿ������һ�㣬��β�������������������һ����㣬���д����൱�ڽ�tempָ��ÿ������������һ�����
					}
					count++;//ÿ������һ�㣬������һ
				}
			}
		}
		return count;
	}
	void DestoryBiTNode(BiTNode*& T)//����������(���ں�������ݹ��㷨һ��һ����µ��ϴ�����һ��һ���ͷŽ����ռ�õ��ڴ�)
	{
		if (T != NULL)//ֻҪ��㲻Ϊ�վ��Ƚ�����������Ȼ���������������ͷŸ���ռ�õĿռ�
		{
			DestoryBiTNode(T->lchild);
			DestoryBiTNode(T->rchild);
			delete[] T;//�ͷſռ�
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
	TElemType key;
	cout << "��������ҵ����ݣ�";
	cin >> key;
	if (tree->FindNode(tree, key))
	{
		cout << "�ڵ㱻���ҵ���" << endl;
	}
	else
	{
		cout << "�ڵ�û�в��ҵ���" << endl;
	}
	cout << "�����������Ҷ����Ϊ��" << tree->CountLeaf(tree) << endl;
	cout << "����������Ĳ���Ϊ��" << tree->CountLayer(tree) << endl;
	tree->DestoryBiTNode(tree);
	cout << "������������ϣ�" << endl;
	return 0;
}