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
	linklist p;
	cout << "元素个数：";
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		p = new lnode;
		cout << "输入数据：";
		cin >> p->data;
		p->next = l->next;
		l->next = p;
	}
}
int display(linklist l)
{
	if (!l)
		return ERROR;
	l = l->next;
	while (l != NULL)
	{
		cout << l->data << ",";
		l = l->next;
	}
	return OK;
}
int main()
{
	linklist l;
	init(l);
	cout << display(l);
}