/*
C++ Stack����ջ�� ��һ��������ĸı࣬Ϊ����Ա�ṩ�˶�ջ��ȫ�����ܡ�
C++ STLջstack��ͷ�ļ�Ϊ:   #include <stack> 
C++ STLջstack�ĳ�Ա�������ܣ�
top()������һ��ջ��Ԫ�ص����ã�����Ϊ T&�����ջΪ�գ�����ֵδ���塣
push(const T& obj)�����Խ����󸱱�ѹ��ջ��������ͨ�����õײ������� push_back() ������ɵġ�
push(T&& obj)�����ƶ�����ķ�ʽ������ѹ��ջ��������ͨ�����õײ�����������ֵ���ò����� push_back() ������ɵġ�
pop()������ջ��Ԫ�ء�
size()������ջ��Ԫ�صĸ�����
empty()����ջ��û��Ԫ�ص�����·��� true��
emplace()���ô���Ĳ������ù��캯������ջ�����ɶ���
swap(stack<T> & other_stack)������ǰջ�е�Ԫ�غͲ����е�Ԫ�ؽ���������������Ԫ�ص����ͱ���͵�ǰջ����ͬ������ stack ������һ����������ȫ�ֺ��� swap() ����ʹ�á�

*/
#include<iostream>
#include<stack>//C++ STLջstack��ͷ�ļ�
using namespace std;
typedef int SElemType;
int main()
{
	//��ӦSqStack st;InitStack(st);
	stack<SElemType>st;//����ջst
	int num;//����������ݸ���
	SElemType temp;//��ʱ����������ר�ã�������Ҫ�����
	cout << "���������ݸ�����";
	cin >> num;
	for (int i = 0; i < num; i++)//����ջ�е�����
	{
		cout << "�������" << i + 1 << "�����ݣ�";
		cin >> temp;
		st.push(temp);//��ջ
	}

	//��ӦPush(st, get);
	cout << "�����������ݣ�";
	cin >> temp;
	st.push(temp);//��ջ

	//��ӦPop(st, out);
	temp = st.top();//��ȡջ��Ԫ��
	st.pop();//��ջ
	cout << "��ջԪ��Ϊ��" << temp << endl;

	//��ӦGetTop(st, read);
	cout << "��ȡ������Ϊ��" << st.top() << endl;//��ȡջ��Ԫ��
	
	//��ӦClearStack(st);
	while (!st.empty())//һֱ��ջ��ջ��
	{
		st.pop();//��ջ
	}

	//��Ӧif (StackEmpty(st) == true)
	if (st.empty())//�ж�ջ��
	{
		cout << "ջ����գ�" << endl;
	}
	else
	{
		cout << "ջ�������ݡ�" << endl;
	}
	return 0;
}