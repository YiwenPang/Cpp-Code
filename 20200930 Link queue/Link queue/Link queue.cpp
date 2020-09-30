#include<iostream>
using namespace std;
typedef int QElemType;//��QElemType�����int
typedef struct QNode
{
	QElemType data;//������
	QNode* next;//ָ����
}QNode, * QueuePtr;//�������еĽ����ж���
typedef struct
{
	QueuePtr front;//ͷָ��
	QueuePtr rear;//βָ��
}LinkQueue;//�����������
void InitQueue_L(LinkQueue& Q)//����������
{
	Q.front = new QNode;//��ͷָ���ϴ���һ�����
	Q.rear = Q.front;//�յ�������ͷβָ��涨����ͬλ��
	Q.front->next = NULL;//�Ȱ�ͷָ����ָ��Ľ��ָ�����ÿ�
}
void EnQueue_L(LinkQueue& Q,QElemType e)//��Ӳ���
{
	QueuePtr p = new QNode;//�ȴ���һ�����
	if (!p)//��һ�������ʧ�ܾͷ���
	{
		cout << "�ڴ����ʧ�ܣ����������" << endl;
		return;
	}
	p->data = e;//���������ֵ��ֵ��������
	p->next = NULL;//���֮��������һ������ˣ�����û�н�㣬����ָ�����ÿ�
	Q.rear->next = p;//����������ӣ�Ҳ������ԭ���е�βָ��ָ��Ľ���ָ����ָ��p
	Q.rear = p;//���������βָ��ָ����Ӻ�Ķ���β�ڵ㣬�������Ļ�����仰�ĳ�Q.rear = Q.rear->next;
}
void DeQueue_L(LinkQueue& Q, QElemType& e)//���Ӳ���
{
	if (Q.front == Q.rear)//�ն�����ɶ��ɾ�ģ�
	{
		cout << "����һ���������У��޷����ӣ����������" << endl;
		return;
	}
	QueuePtr p;//�ȴ���һ�����
	p = Q.front->next;//������֪��ͷָ�����ӵ�ͷ���û���ݣ����Ǹ�ͷ���ѣ�����ͷ������һ����������Ҫ���ӵĽ�㣬����pָ��׼�����ӵĵط�
	e = p->data;//�Ȱ�׼�����ӵ����ݶ������ŵ�e
	Q.front->next = p->next;//�߶����ˣ����������ָ�����ͷ���ɣ�������ɾ��֮��ͷ��������������һ�����
	if (Q.rear == p)//ɶ������βָ��ָ����Ǹ��ڵ㣬�����˶��в��Ϳ��ˣ��������ָ����ɶҲû�У��Ǿ���βָ��ָ��ͷ����
	{
		Q.rear = Q.front;//��βָ��ָ��ͷָ��ָ��ĵط�
	}
	delete p;//�ͷŵ�������Ŀռ�
}
void DestroyQueue_L(LinkQueue& Q)//����Ļٵ��������
{
	QueuePtr temp;//�ȴ���һ�����
	while (Q.front != Q.rear)//ֻҪ���в��գ��Ǿͼ���ѭ��
	{
		temp = Q.front;//����tempָ��ͷָ��ָ���λ��
		Q.front = Q.front->next;//ͷָ��������һ�����
		delete[]temp;//tempָ��ĵط��ͷſռ�
	}
	delete[]Q.front;//��Q.front==Q.rearʱ�޷�����ѭ�����ͻ�ʣ����һ����㣬������ҲҪ�ͷſռ�
}
int main()
{
	LinkQueue Q;//���������� 
	InitQueue_L(Q);//��ʼ�������� 
	QElemType e;
	int n, m;
	cout << "��������ջԪ�ظ�����";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "����ӵ����ݣ�";
		cin >> e;
		EnQueue_L(Q, e);
	}
	cout << "�������ջԪ�ظ�����";
	cin >> m;
	while (m > n)
	{
		cout << "��ջԪ�ش�����ջԪ�أ����������룺";
		cin >> m;
	}
	for (int i = 0; i < m; i++)
	{
		DeQueue_L(Q, e);
		cout << "���ӵĵ�" << i + 1 << "������Ϊ��" << e << endl;
	}
	DestroyQueue_L(Q);
	return 0;
