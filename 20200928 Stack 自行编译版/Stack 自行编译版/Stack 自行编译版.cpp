#include<iostream>
#include<stdlib.h>//������Ϊɶ���������ֻ֪�������������õĶ���
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct
{
	SElemType* base;//βָ�룬ָ��ջ�ĵ׶�
	SElemType* top;//��ָ�룬ָ��ջ�Ķ���
	int stacksize;//��¼ջ���ܴ�С
}SqStack;
void InitStack(SqStack& st)//����ջ
{
	st.base = new SElemType[STACK_INIT_SIZE];//��βָ�봴��ջ�Ķ�
	st.top = st.base;//��Ϊ����ջ��ɶҲû�У����Զ�ָ���βָ���λ��һ��
	st.stacksize = STACK_INIT_SIZE;//����ջ���ܴ�С���ǿ��ٵĿռ�
	int num;//���ڴ�����������ݸ���
	cout << "���������ݸ�����";
	cin >> num;
	while (num > st.stacksize)//���������ջ���ܴ�С��ջ�����
	{
		cout << "���������ܻᵼ����������������룺";
		cin >> num;
	}
	for (int i = 0; i < num; i++)//����ջ�е�����
	{
		cout << "�������" << i + 1 << "�����ݣ�";
		cin >> *((++st.top) - 1);//��仰�ܾ��ɣ�����st.top������һ����ַ��Ȼ����ԭ��st.top���ڵ�λ����������
	}
}
void DestoryStack(SqStack& st)//�������ջ
{
	st.top = st.base;//����st.topָ��st.base���൱��������
	delete[]st.base;//�������ջ�Ķ�
}
void ClearStack(SqStack& st)//���������ջ��������ÿ�
{
	st.top = st.base;//�ܼ򵥣��ö�ָ��ָ��βָ����У������ط�������ɶ���ݶ�����Ч���ݲ��ù�
}
void GetTop(SqStack st, SElemType& get)//��ȡջ��Ч����Ķ�������
{
	get = *(st.top - 1);//��Ϊ�������������ڶ�ָ���ǰһ����ַ�����st.top-1������ͷͷ�����ݣ�st.top��û���ݵĻ�������Ч����
}
void Push(SqStack& st, SElemType e)//��ջ����
{
	if (st.top - st.base >= st.stacksize)//�����ջ����������ô����ջ�������һ��ջ�Ŀռ�Ҳ��д�����ݺ�st.top�ͻ��ܵ�ջ������
	{
		st.base = (SElemType*)realloc(st.base, ((st.top - st.base) + STACKINCREMENT) * sizeof(SElemType));//����STACKINCREMENT���ռ�
		if (!st.base)//��һ��ķ���ռ�ʧ�ܣ��Ǿ�ֻ�ܷ�����
		{
			cout << "�ڴ����ʧ�ܣ�Push()���ˣ�" << endl;
			return;
		}
		st.top = st.base + st.stacksize;//��st.topָ�����䲿�ֵĵ�һ�����ݵ�
		st.stacksize += STACKINCREMENT;//����ջ���ܴ�С
	}
	*st.top++ = e;//��д������Ȼ������st.top������
}
void Pop(SqStack& st, SElemType& out)//��ջ����
{
	out = *(--st.top);//���ö�ָ�����һ����ַ��Ȼ���ڶ�ȡ���λ���ϵ����ݣ�����ȥ������ݺ����ڶ�������Ѿ���Ϊ����Ч���ݣ��൱����ջ��
}
bool StackEmpty(SqStack st)//����ջ�ǲ��ǿյģ�����ǿյģ��Ǿͷ���true�����򷵻�false
{
	if (st.top == st.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	SqStack st;
	InitStack(st);
	SElemType get, out, read;
	cout << "�����������ݣ�";
	cin >> get;
	Push(st, get);
	Pop(st, out);
	cout << "��ջԪ��Ϊ��" << out << endl;
	GetTop(st, read);
	cout << "��ȡ������Ϊ��" << read << endl;
	ClearStack(st);
	if (StackEmpty(st) == true)
	{
		cout << "ջ����գ�" << endl;
	}
	else
	{
		cout << "ջ�������ݡ�" << endl;
	}
	return 0;
}