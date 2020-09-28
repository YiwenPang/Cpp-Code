/*
��Һã��������Ͼ�Ҫ�������ű������ˣ������ʱ���һ���Ⱥ�﷢һЩ���룬��ҿ��Խ��и�ϰ����Ҫ�������ݵĽṹ����Ŀ������
�����ǶԶ��������н��ͺͶԴ���Ľ���
��Ҫ֪����֪ʶ�У��βκ�ʵ�Σ��������������ָ��
��Ҳ����ĵط�������ѧ
*/
#include<iostream>
using namespace std;
typedef char TElemType;//���¶���charΪTElemType
class BiTNode
{
private:
	TElemType data;//������
	BiTNode* lchild, * rchild;//��������������
public:
	BiTNode()//����Ϊ�յĹ��캯���������������������ÿ�
	{
		lchild = NULL;
		rchild = NULL;
	}
	BiTNode(TElemType d,BiTNode *lc,BiTNode *rc)//������Ϊ�յĹ��캯����д�����������������
	{
		data = d;
		lchild = lc;
		rchild = rc;
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
	void DLR(BiTNode*& T)//����������ȱ��������ٱ�����������������������
	{
		if (T != NULL)//����ǿ������Ͳ�Ҫ�����
		{
			cout << T->data;//�ȱ��������Ѹ����������
			DLR(T->lchild);//�õݹ�İ취�ȱ���������
			DLR(T->rchild);//ͬ��Ҳ�ǵݹ飬����������������������
		}
	}
	void LDR(BiTNode*& T)//����������ȱ������������ٱ�������������������
	{
		if (T != NULL)//����ǿ������Ͳ�Ҫ�����
		{
			LDR(T->lchild);//�õݹ�İ취�ȱ���������
			cout << T->data;//���������������������Ѹ����������
			LDR(T->rchild);//ͬ��Ҳ�ǵݹ飬�����������������
		}
	}
	void LRD(BiTNode*& T)//����������ȱ������������ٱ�������������������
	{
		if (T != NULL)//����ǿ������Ͳ�Ҫ�����
		{
			LRD(T->lchild);//�õݹ�İ취�ȱ���������
			LRD(T->rchild);//ͬ��Ҳ�ǵݹ飬����������������������
			cout << T->data;//�����������Ѹ����������
		}
	}
};
int main()
{
	BiTNode* tree;//�ȴ���һ�����������ܸ�
	cout << "������������ǰ���������������������Ϊ���ÿո�ռλ��";
	tree->CreateBiTree(tree);//��ʼһ��һ����ȡcin.get()�����������
	cout << "����������Ϊ��";
	tree->DLR(tree);
	cout << endl << "����������Ϊ��";
	tree->LDR(tree);
	cout << endl << "����������Ϊ��";
	tree->LRD(tree);
	return 0;
}