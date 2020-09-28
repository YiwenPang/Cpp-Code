#include<iostream>
using namespace std;
typedef int Elemtype;//��int�ı���ΪElemtype
typedef struct LNode//����������������
{
	Elemtype data;//������
	LNode* next;//ָ����
}*Linklist;
int m;//��Ҫ������Ԫ��������Head1�ģ�
int n;//��Ҫ������Ԫ��������Head2�ģ�
void InitList(Linklist& Head, int& count)
{
	Linklist temp;//��������ڵ㣬������ʱ��Head����
	cout << "�����봴����Ԫ������";
	cin >> count;
	Head = new LNode;//����ͷ�ڵ�
	Head->next = NULL;//���ƿգ��ں���Ĵ����н��в��빤��
	for (int i = 0; i < count; i++)//�������
	{
		temp = new LNode;//�����������ڵ�
		cout << "�������" << count - i << "�����ݣ�";
		cin >> temp->data;//�����������ڵ��������
		temp->next = Head->next;//��Head��ָ�����temp��ָ��������temp��ָ�������ָ��ԭ��Headָ��ĵط�
		Head->next = temp;//��ͷ�ڵ��ָ����ָ��temp�����������������ӣ�ͷ�ڵ�ָ��temp��temp��ָ�����Ľڵ㣬�������������벢����һ����
	}
}
void Output(Linklist Head, int count)//��Ȼ������Ͳ�������ô��Ȩ���ˣ�ֱ���βθ�ֵ����
{
	Linklist temp = new LNode;//����һ���ڵ㣬������ָ����ȥ�������е������ϵĽڵ�
	temp->next = Head->next;//����temp��ָ����ָ��Head��nextָ��ĵط���Ҳ���ǵ�һ�������ݵĽڵ�
	for (int i = 0; i < count; i++)
	{
		cout << "��" << i + 1 << "�������ǣ�" << temp->next->data << endl;
		if (temp->next == NULL)
		{
			break;//������û�нڵ������������
		}
		else
		{
			temp->next = temp->next->next;//�����д�����tempһ��һ���ı������еĽڵ�
		}
	}
}
void ListInsert(Linklist& Head, int& count)//���������õĺ���
{
	Linklist temp1, temp2 = new LNode;//temp1��������λ�ģ�temp2�������������������ݵ�
	temp1 = Head->next;
	int dLocal;//�����û������λ��
	cout << "�������������һ��Ԫ��֮ǰ��";
	cin >> dLocal;
	for (int i = 0; i < dLocal - 2; i++)//������temp1����λ����Ҫ���뵽ָ��λ���ִ��ڵĽڵ�
	{
		temp1 = temp1->next;
	}
	cout << "�������������ݣ�";
	cin >> temp2->data;//������Ҫ����Ľڵ��������
	temp2->next = temp1->next;//��temp2��nextָ��temp1ָ���next
	temp1->next = temp2;//��������
	count++;
}
void ListDelete(Linklist& Head, int& count)//ɾ��ĳ���ڵ��õĺ���
{
	Linklist temp1 = Head->next;//temp1��������λɾ����λ�õ�
	int dLocal;//��¼�û�ɾ����λ���õ���
	cout << "������ɾ��Ԫ�ص�λ�ã�";
	cin >> dLocal;
	for (int i = 0; i < dLocal - 2; i++)//��forѭ������λ����ɾ���Ľڵ��ǰһ���ڵ�
	{
		temp1 = temp1->next;
	}
	Linklist temp2 = temp1->next;//��temp2��λ׼��ɾ���Ľڵ�
	temp1->next = temp1->next->next;//��temp1ָ��׼��ɾ���ڵ����һ���ڵ�
	delete temp2;//�ͷſռ�
	count--;
}
Linklist ListMerge(Linklist& Head1, Linklist& Head2)//���Ŵ�С�ߺϲ�
{
	Linklist Merge = new LNode;
	Linklist temp1 = Head1->next, temp2 = Head2->next, temp3 = Merge;
	int i = 0, j = 0;//�Ʋ�������¼�Ѿ����Merge��Ľڵ������i��¼Head1�ģ�j��¼Head2��
	while (i != m && j != n)//ֻҪ����һ��û����ͼ�����
	{
		if (temp1->data < temp2->data)//���Ǹ����ݴ�С�������Ȳ���
		{
			temp3->next = temp1;//�ȸı�temp3��ָ����ָ���λ��
			temp3 = temp3->next;//��temp3ָ��ղ���Ľڵ�
			temp1 = temp1->next;//temp1������һ���ڵ�
			i++;
		}
		else
		{
			temp3->next = temp2;
			temp3 = temp3->next;
			temp2 = temp2->next;
			j++;
		}
	}
	if (i == m)//ʣ�µ�ȫ����
	{
		temp3->next = temp2;
	}
	else
	{
		temp3->next = temp1;
	}
	return Merge;
}
int main()
{
	Linklist Head1, Head2, HeadMerge;
	InitList(Head1, m);
	Output(Head1, m);
	ListInsert(Head1, m);
	Output(Head1, m);
	ListDelete(Head1, m);
	Output(Head1, m);
	InitList(Head2, n);
	Output(Head2, n);
	HeadMerge = ListMerge(Head1, Head2);
	Output(HeadMerge, m + n);
	return 0;
}