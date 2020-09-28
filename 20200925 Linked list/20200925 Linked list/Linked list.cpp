#include<iostream>
using namespace std;
typedef int Elemtype;//令int的别名为Elemtype
typedef struct LNode//创建链表数据类型
{
	Elemtype data;//数据域
	LNode* next;//指针域
}*Linklist;
int m;//想要创建的元素数量（Head1的）
int n;//想要创建的元素数量（Head2的）
void InitList(Linklist& Head, int& count)
{
	Linklist temp;//创建链表节点，在生成时和Head链接
	cout << "请输入创建的元素数：";
	cin >> count;
	Head = new LNode;//创建头节点
	Head->next = NULL;//先制空，在后面的代码中进行插入工作
	for (int i = 0; i < count; i++)//倒叙插入
	{
		temp = new LNode;//生成这个链表节点
		cout << "请输入第" << count - i << "个数据：";
		cin >> temp->data;//输入这个链表节点的数据域
		temp->next = Head->next;//将Head的指针域给temp的指针域，这样temp的指针域就能指向原来Head指向的地方
		Head->next = temp;//将头节点的指针域指向temp，完成整个链表的链接，头节点指向temp，temp又指向后面的节点，就这样后续插入并穿成一个串
	}
}
void Output(Linklist Head, int count)//既然是输出就不给他那么多权限了，直接形参赋值就行
{
	Linklist temp = new LNode;//创建一个节点，用它的指针域去遍历所有的链表上的节点
	temp->next = Head->next;//先让temp的指针域指向Head的next指向的地方，也就是第一个有数据的节点
	for (int i = 0; i < count; i++)
	{
		cout << "第" << i + 1 << "个数据是：" << temp->next->data << endl;
		if (temp->next == NULL)
		{
			break;//遍历到没有节点就跳出来结束
		}
		else
		{
			temp->next = temp->next->next;//用这行代码让temp一个一个的遍历所有的节点
		}
	}
}
void ListInsert(Linklist& Head, int& count)//插入数据用的函数
{
	Linklist temp1, temp2 = new LNode;//temp1是用来定位的，temp2是用来存插入的数据内容的
	temp1 = Head->next;
	int dLocal;//储存用户输入的位置
	cout << "请输入插入在哪一个元素之前：";
	cin >> dLocal;
	for (int i = 0; i < dLocal - 2; i++)//用来让temp1来定位到需要插入到指定位置现存在的节点
	{
		temp1 = temp1->next;
	}
	cout << "请输入插入的数据：";
	cin >> temp2->data;//输入需要插入的节点的数据域
	temp2->next = temp1->next;//让temp2的next指向temp1指向的next
	temp1->next = temp2;//连上链表
	count++;
}
void ListDelete(Linklist& Head, int& count)//删除某个节点用的函数
{
	Linklist temp1 = Head->next;//temp1是用来定位删除的位置的
	int dLocal;//记录用户删除的位置用的数
	cout << "请输入删除元素的位置：";
	cin >> dLocal;
	for (int i = 0; i < dLocal - 2; i++)//用for循环来定位到被删除的节点的前一个节点
	{
		temp1 = temp1->next;
	}
	Linklist temp2 = temp1->next;//用temp2定位准备删除的节点
	temp1->next = temp1->next->next;//让temp1指向准备删除节点的下一个节点
	delete temp2;//释放空间
	count--;
}
Linklist ListMerge(Linklist& Head1, Linklist& Head2)//边排大小边合并
{
	Linklist Merge = new LNode;
	Linklist temp1 = Head1->next, temp2 = Head2->next, temp3 = Merge;
	int i = 0, j = 0;//计步器，计录已经插进Merge里的节点个数，i记录Head1的，j记录Head2的
	while (i != m && j != n)//只要其中一个没插完就继续插
	{
		if (temp1->data < temp2->data)//比那个数据大，小的数据先插入
		{
			temp3->next = temp1;//先改变temp3的指针域指向的位置
			temp3 = temp3->next;//让temp3指向刚插入的节点
			temp1 = temp1->next;//temp1移向下一个节点
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
	if (i == m)//剩下的全接上
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