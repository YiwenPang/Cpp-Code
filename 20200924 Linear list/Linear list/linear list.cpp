#include<iostream>
#include<stdlib.h>//�漰���ѵ�����
using namespace std;
struct Student//��StudentΪ���������Ա�
{
	char name[9];
	char number[8];
	int age;
	double score;
};
typedef Student Elemtype;//����Student�ı���Elemtype,����Elemtype���񿴼���Studentһ��
typedef struct//���Ա�Ľṹ��
{
	Elemtype* elem;//�ö�����ķ�ʽ�洢Student����
	int length;//������Ŀǰ�ĳ���
	int listsize;//��������ܴ�С
}SqList;
#define LIST_INIT_SIZE 100//����ÿ�����Ա��Ӧ�Ķ�������ʼ��С
#define LISTINCREMENT 10//����ÿ�����Ա��Ӧ�Ķ����鲻��ʱ����Ķ������С
void InitList(SqList& L)//�������Ա���й������Ա�
{
	L.elem = new Elemtype[LIST_INIT_SIZE];//�������Ա��ElemType��
	L.length = 0;//Ŀǰ����Ϊ0
	L.listsize = LIST_INIT_SIZE;//Ŀǰ����LIST_INIT_SIZE��Elemtype�ռ�
}
void Input(SqList& L)//���������õĺ��������������һ��Bug�������ܲ�������ݲ��ܳ���LIST_INIT_SIZE��
{
	int nsum;//���������Elemtype�ĸ���
	cin >> nsum;
	for (int i = 0; i < nsum; i++)
	{
		cin >> L.elem[i].name >> L.elem[i].number >> L.elem[i].age >> L.elem[i].score;
		L.length++;//ÿ����һ��Elemtype�ͳ��ȼ�һ
	}
}
void Output(SqList& L)//���ģ�飬�������Elemtype
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i].name << " " << L.elem[i].number << " " << L.elem[i].age << " " << L.elem[i].score << endl;
	}
}
void ListInsert(SqList& L)//������Elemtype������������õĺ���
{
	int dLocal;//������Ҫ�����Elemtype��λ��
	cout << "���������Ԫ�ص�λ��(1-"<<L.length<<"):" << endl;//���뵽��dLocalԪ�ص�ǰ�棬ע������������±��Ǵ�1��ʼ�ģ���ʵ�ʵ��±��Ǵ��㿪ʼ��
	cin >> dLocal;
	while (dLocal <= 0 || dLocal > L.length)//��Ҫ����ͱ������м����
	{
		cout << "����������(1-n):" << endl;
		cin >> dLocal;
	}
	if (L.length >= L.listsize)//�����������������������
	{
		L.elem = (Elemtype*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Elemtype));
	}
	for (int i = L.length; i >= dLocal; i--)//�Ȱ�ԭ������������Ų��ע������������±��Ǵ�1��ʼ�ģ���ʵ�ʵ��±��Ǵ��㿪ʼ��
	{
		L.elem[i] = L.elem[i - 1];
	}
	cout << "�������������ݣ�";
	cin >> L.elem[dLocal - 1].name >> L.elem[dLocal - 1].number >> L.elem[dLocal - 1].age >> L.elem[dLocal - 1].score;//ע������������±��Ǵ�1��ʼ�ģ���ʵ�ʵ��±��Ǵ��㿪ʼ��
	L.length++;//ÿ����һ����ЧElemtype���Ⱦͼ�һ
}
void ListDelete(SqList& L)//������Elemtype����ɾ��ĳһ�����õĺ���
{
	if (L.length == 0)//�ձ�����û��Ԫ�أ����Բ��ܽ���ɾ������
	{
		cout << "�ձ���ɾ����" << endl;
		return;
	}
	int dLocal;//��Ҫɾ����λ��,ע������������±��Ǵ�1��ʼ�ģ���ʵ�ʵ��±��Ǵ��㿪ʼ��
	while (dLocal <= 0 || dLocal > L.length)//��Ҫɾ���Ͳ���Խ��
	{
		cout << "����������(1-n):" << endl;
		cin >> dLocal;
	}
	for (int i = dLocal - 1; i < L.length; i++)//ע������������±��Ǵ�1��ʼ�ģ���ʵ�ʵ��±��Ǵ��㿪ʼ��
	{
		L.elem[i] = L.elem[i + 1];//������ǰŲ
	}
	L.length--;//ÿɾ��һ�����ݳ��Ⱦͼ�һ
}
void ListFind(SqList L)//������Ϊ��Ѱ��ĳ�����ݣ��Ͳ���������ô�ߵ�Ȩ����
{
	char Target[8];//������׼����ѯ��ѧ��
	bool ifTarget;//��¼�Ƿ��ҵ������ѧ��
	int dLocal;//����ҵ��ˣ�������¼λ��
	cout << "��������Ҫ���ҵ�ѧ�ţ�";
	cin >> Target;
	for (int i = 0; i < L.length; i++)//һ������һ�����ݵı���
	{
		ifTarget = strcmp(L.elem[i].number, Target);//����鵽�ˣ�����0��ifTarget�����򷵻�1
		if (ifTarget == 0)//����鵽�ˣ���ô�Ͱ��±��¼����
		{
			dLocal = i;
			break;
		}
	}
	if (ifTarget == 0)
	{
		cout << "�ҵ���Ԫ�أ������ڵ�" << dLocal + 1 << "��λ�á�" << endl;
	}
	else
	{
		cout << "��û���ҵ���Ҫ�ҵģ�" << endl;
	}
}
int main()
{
	SqList list;
	InitList(list);
	Input(list);
	Output(list);
	ListInsert(list);
	Output(list);
	ListDelete(list);
	Output(list);
	system("PAUSE");
	return 0;
}