/*
C++ Stack（堆栈） 是一个容器类的改编，为程序员提供了堆栈的全部功能。
C++ STL栈stack的头文件为:   #include <stack> 
C++ STL栈stack的成员函数介绍：
top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
pop()：弹出栈顶元素。
size()：返回栈中元素的个数。
empty()：在栈中没有元素的情况下返回 true。
emplace()：用传入的参数调用构造函数，在栈顶生成对象。
swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。

*/
#include<iostream>
#include<stack>//C++ STL栈stack的头文件
using namespace std;
typedef int SElemType;
int main()
{
	//对应SqStack st;InitStack(st);
	stack<SElemType>st;//创建栈st
	int num;//存输入的数据个数
	SElemType temp;//临时变量，万能专用，哪里需要哪里搬
	cout << "请输入数据个数：";
	cin >> num;
	for (int i = 0; i < num; i++)//输入栈中的数据
	{
		cout << "请输入第" << i + 1 << "个数据：";
		cin >> temp;
		st.push(temp);//入栈
	}

	//对应Push(st, get);
	cout << "输入插入的数据：";
	cin >> temp;
	st.push(temp);//入栈

	//对应Pop(st, out);
	temp = st.top();//读取栈顶元素
	st.pop();//出栈
	cout << "退栈元素为：" << temp << endl;

	//对应GetTop(st, read);
	cout << "读取的数据为：" << st.top() << endl;//读取栈顶元素
	
	//对应ClearStack(st);
	while (!st.empty())//一直出栈到栈空
	{
		st.pop();//出栈
	}

	//对应if (StackEmpty(st) == true)
	if (st.empty())//判断栈空
	{
		cout << "栈已请空！" << endl;
	}
	else
	{
		cout << "栈内有数据。" << endl;
	}
	return 0;
}