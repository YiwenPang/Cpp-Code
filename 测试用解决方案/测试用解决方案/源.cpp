#include<iostream>
using namespace std;
#define ERROR (0)
#define OK (1)
typedef int elemtype;
typedef struct lnode
{
	elemtype data;
	lnode* next;
}lnode, * linklist;
void init(linklist& l)
{
	l = new lnode;
	l->next = NULL;
	linklist p, temp=l;
	cout << "元素个数：";
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		p = new lnode;
		cout << "输入数据：";
		cin >> p->data;
		temp->next = p;
		p->next = NULL;
		temp = temp->next;
	}
}
int display(linklist l)
{
	if (!l)
		return ERROR;
	l = l->next;
	while (1)
	{
		cout << l->data << ",";
		l = l->next;
		if (l->next == NULL)
		{
			cout << l->data;
			break;
		}
	}
	return OK;
}
void jiehe(linklist& l1, linklist& l2)
{
	linklist pa, pb, pc, l3;
	pa = l1->next;  pb = l2->next;
	l3 = pc = l1;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa; pc = pa;  pa = pa->next;
		}
		else
		{
			pc->next = pb;  pc = pb;  pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete  l2;
	display(l3);
}
int main()
{
	linklist l1, l2;
	init(l1);
	init(l2);
	display(l1);
	display(l2);
	cout << "结合后为：";
	jiehe(l1, l2);
}