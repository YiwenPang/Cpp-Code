#include<iostream>
using namespace std;
typedef int QElemType;//将QElemType定义成int
typedef struct QNode
{
	QElemType data;//数据域
	QNode* next;//指针域
}QNode, * QueuePtr;//对链队列的结点进行定义
typedef struct
{
	QueuePtr front;//头指针
	QueuePtr rear;//尾指针
}LinkQueue;//定义队列类型
void InitQueue_L(LinkQueue& Q)//创建链队列
{
	Q.front = new QNode;//在头指针上创建一个结点
	Q.rear = Q.front;//空的链队列头尾指针规定在相同位置
	Q.front->next = NULL;//先把头指针所指向的结点指针域置空
}
void EnQueue_L(LinkQueue& Q,QElemType e)//入队操作
{
	QueuePtr p = new QNode;//先创建一个结点
	if (!p)//万一创建结点失败就返回
	{
		cout << "内存分配失败，程序结束！" << endl;
		return;
	}
	p->data = e;//将输入进的值赋值给数据域
	p->next = NULL;//入队之后就是最后一个结点了，下面没有结点，所以指针域置空
	Q.rear->next = p;//将这个结点入队，也就是让原队列的尾指针指向的结点的指针域指向p
	Q.rear = p;//这里就是让尾指针指向入队后的队列尾节点，不好理解的话把这句话改成Q.rear = Q.rear->next;
}
void DeQueue_L(LinkQueue& Q, QElemType& e)//出队操作
{
	if (Q.front == Q.rear)//空队列有啥好删的？
	{
		cout << "这是一个空链队列！无法出队！程序结束！" << endl;
		return;
	}
	QueuePtr p;//先创建一个结点
	p = Q.front->next;//总所周知，头指针连接的头结点没数据，就是个头而已，所以头结点的下一个才是我们要出队的结点，先让p指向准备出队的地方
	e = p->data;//先把准备出队的数据读出来放到e
	Q.front->next = p->next;//走都走了，就留下你的指针域给头结点吧，这样你删了之后头结点能连接你的下一个结点
	if (Q.rear == p)//啥？你是尾指针指向的那个节点，你走了队列不就空了，而且你的指针域啥也没有，那就让尾指针指向头结点吧
	{
		Q.rear = Q.front;//让尾指针指向头指针指向的地方
	}
	delete p;//释放掉这个结点的空间
}
void DestroyQueue_L(LinkQueue& Q)//无情的毁掉这个队列
{
	QueuePtr temp;//先创建一个结点
	while (Q.front != Q.rear)//只要队列不空，那就继续循环
	{
		temp = Q.front;//先让temp指向头指针指向的位置
		Q.front = Q.front->next;//头指针往下走一个结点
		delete[]temp;//temp指向的地方释放空间
	}
	delete[]Q.front;//当Q.front==Q.rear时无法进入循环，就会剩下来一个结点，这个结点也要释放空间
}
int main()
{
	LinkQueue Q;//创建链队列 
	InitQueue_L(Q);//初始化链队列 
	QElemType e;
	int n, m;
	cout << "请输入入栈元素个数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个入队的数据：";
		cin >> e;
		EnQueue_L(Q, e);
	}
	cout << "请输入出栈元素个数：";
	cin >> m;
	while (m > n)
	{
		cout << "出栈元素大于入栈元素，请重新输入：";
		cin >> m;
	}
	for (int i = 0; i < m; i++)
	{
		DeQueue_L(Q, e);
		cout << "出队的第" << i + 1 << "个数据为：" << e << endl;
	}
	DestroyQueue_L(Q);
	return 0;
