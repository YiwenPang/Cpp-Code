#include<iostream>
#include<stdlib.h>//涉及到堆的扩充
using namespace std;
struct Student//以Student为例创建线性表
{
	char name[9];
	char number[8];
	int age;
	double score;
};
typedef Student Elemtype;//定义Student的别名Elemtype,看见Elemtype就像看见了Student一样
typedef struct//线性表的结构体
{
	Elemtype* elem;//用堆数组的方式存储Student数组
	int length;//堆数组目前的长度
	int listsize;//堆数组的总大小
}SqList;
#define LIST_INIT_SIZE 100//定义每个线性表对应的堆数组起始大小
#define LISTINCREMENT 10//定义每个线性表对应的堆数组不够时扩充的堆数组大小
void InitList(SqList& L)//引用线性表进行构建线性表
{
	L.elem = new Elemtype[LIST_INIT_SIZE];//构建线性表的ElemType堆
	L.length = 0;//目前长度为0
	L.listsize = LIST_INIT_SIZE;//目前开了LIST_INIT_SIZE个Elemtype空间
}
void Input(SqList& L)//输入数据用的函数，这个函数有一个Bug，就是能插入的数据不能超过LIST_INIT_SIZE个
{
	int nsum;//定义输入的Elemtype的个数
	cin >> nsum;
	for (int i = 0; i < nsum; i++)
	{
		cin >> L.elem[i].name >> L.elem[i].number >> L.elem[i].age >> L.elem[i].score;
		L.length++;//每输入一个Elemtype就长度加一
	}
}
void Output(SqList& L)//输出模块，用于输出Elemtype
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i].name << " " << L.elem[i].number << " " << L.elem[i].age << " " << L.elem[i].score << endl;
	}
}
void ListInsert(SqList& L)//用于在Elemtype堆里插入数据用的函数
{
	int dLocal;//定义想要插入的Elemtype的位置
	cout << "请输入插入元素的位置(1-"<<L.length<<"):" << endl;//插入到第dLocal元素的前面，注意这里的输入下标是从1开始的，而实际的下标是从零开始的
	cin >> dLocal;
	while (dLocal <= 0 || dLocal > L.length)//想要插入就必须在中间插入
	{
		cout << "请重新输入(1-n):" << endl;
		cin >> dLocal;
	}
	if (L.length >= L.listsize)//如果堆容量不够就扩充容量
	{
		L.elem = (Elemtype*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Elemtype));
	}
	for (int i = L.length; i >= dLocal; i--)//先把原来的数据往后挪，注意这里的输入下标是从1开始的，而实际的下标是从零开始的
	{
		L.elem[i] = L.elem[i - 1];
	}
	cout << "请输入插入的数据：";
	cin >> L.elem[dLocal - 1].name >> L.elem[dLocal - 1].number >> L.elem[dLocal - 1].age >> L.elem[dLocal - 1].score;//注意这里的输入下标是从1开始的，而实际的下标是从零开始的
	L.length++;//每插入一个有效Elemtype长度就加一
}
void ListDelete(SqList& L)//用于在Elemtype堆里删除某一数据用的函数
{
	if (L.length == 0)//空表本来就没有元素，所以不能进行删除操作
	{
		cout << "空表不能删除！" << endl;
		return;
	}
	int dLocal;//想要删除的位置,注意这里的输入下标是从1开始的，而实际的下标是从零开始的
	while (dLocal <= 0 || dLocal > L.length)//想要删除就不能越界
	{
		cout << "请重新输入(1-n):" << endl;
		cin >> dLocal;
	}
	for (int i = dLocal - 1; i < L.length; i++)//注意这里的输入下标是从1开始的，而实际的下标是从零开始的
	{
		L.elem[i] = L.elem[i + 1];//数据往前挪
	}
	L.length--;//每删除一个数据长度就减一
}
void ListFind(SqList L)//这里是为了寻找某个数据，就不用引用这么高的权限了
{
	char Target[8];//用来存准备查询的学号
	bool ifTarget;//记录是否找到了这个学号
	int dLocal;//如果找到了，用来记录位置
	cout << "请输入需要查找的学号：";
	cin >> Target;
	for (int i = 0; i < L.length; i++)//一个数据一个数据的遍历
	{
		ifTarget = strcmp(L.elem[i].number, Target);//如果查到了，返回0给ifTarget，否则返回1
		if (ifTarget == 0)//如果查到了，那么就把下标记录下来
		{
			dLocal = i;
			break;
		}
	}
	if (ifTarget == 0)
	{
		cout << "找到了元素，它排在第" << dLocal + 1 << "个位置。" << endl;
	}
	else
	{
		cout << "并没有找到您要找的！" << endl;
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