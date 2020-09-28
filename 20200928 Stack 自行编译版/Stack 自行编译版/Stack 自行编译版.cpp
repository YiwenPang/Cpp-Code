#include<iostream>
#include<stdlib.h>//别问我为啥加这个，我只知道这里有我想用的东西
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct
{
	SElemType* base;//尾指针，指向栈的底端
	SElemType* top;//顶指针，指向栈的顶端
	int stacksize;//记录栈的总大小
}SqStack;
void InitStack(SqStack& st)//创建栈
{
	st.base = new SElemType[STACK_INIT_SIZE];//用尾指针创建栈的堆
	st.top = st.base;//因为现在栈里啥也没有，所以顶指针和尾指针的位置一样
	st.stacksize = STACK_INIT_SIZE;//现在栈的总大小就是开辟的空间
	int num;//用于储存输入的数据个数
	cout << "请输入数据个数：";
	cin >> num;
	while (num > st.stacksize)//如果超过了栈的总大小，栈会溢出
	{
		cout << "这样做可能会导致溢出，请重新输入：";
		cin >> num;
	}
	for (int i = 0; i < num; i++)//输入栈中的数据
	{
		cout << "请输入第" << i + 1 << "个数据：";
		cin >> *((++st.top) - 1);//这句话很精巧，先让st.top往后走一个地址，然后在原来st.top所在的位置填上数据
	}
}
void DestoryStack(SqStack& st)//销毁这个栈
{
	st.top = st.base;//先让st.top指向st.base，相当于清零了
	delete[]st.base;//销毁这个栈的堆
}
void ClearStack(SqStack& st)//不销毁这个栈的情况下置空
{
	st.top = st.base;//很简单，让顶指针指向尾指针就行，其他地方无论是啥数据都算无效数据不用管
}
void GetTop(SqStack st, SElemType& get)//获取栈有效区域的顶部数据
{
	get = *(st.top - 1);//因为顶部的数据是在顶指针的前一个地址里，所以st.top-1才是最头头的数据，st.top里没数据的或者是无效数据
}
void Push(SqStack& st, SElemType e)//入栈操作
{
	if (st.top - st.base >= st.stacksize)//如果入栈后会溢出，那么就扩栈，当最后一个栈的空间也被写入数据后，st.top就会跑到栈的外面
	{
		st.base = (SElemType*)realloc(st.base, ((st.top - st.base) + STACKINCREMENT) * sizeof(SElemType));//扩充STACKINCREMENT个空间
		if (!st.base)//万一真的分配空间失败，那就只能返回了
		{
			cout << "内存分配失败，Push()终了！" << endl;
			return;
		}
		st.top = st.base + st.stacksize;//让st.top指向扩充部分的第一个数据点
		st.stacksize += STACKINCREMENT;//更新栈的总大小
	}
	*st.top++ = e;//先写好数据然后再让st.top往后走
}
void Pop(SqStack& st, SElemType& out)//退栈操作
{
	out = *(--st.top);//先让顶指针后退一个地址，然后在读取这个位置上的数据，看上去这个数据好像还在堆里，但是已经成为了无效数据，相当于退栈了
}
bool StackEmpty(SqStack st)//看看栈是不是空的，如果是空的，那就返回true，否则返回false
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
	cout << "输入插入的数据：";
	cin >> get;
	Push(st, get);
	Pop(st, out);
	cout << "退栈元素为：" << out << endl;
	GetTop(st, read);
	cout << "读取的数据为：" << read << endl;
	ClearStack(st);
	if (StackEmpty(st) == true)
	{
		cout << "栈已请空！" << endl;
	}
	else
	{
		cout << "栈内有数据。" << endl;
	}
	return 0;
}