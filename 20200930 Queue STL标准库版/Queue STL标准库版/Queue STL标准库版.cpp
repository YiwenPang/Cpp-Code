/*
栈都有STL标准库这么方便的东西，队列也有。
queue 和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同：
front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
pop()：删除 queue 中的第一个元素。
size()：返回 queue 中元素的个数。
empty()：如果 queue 中没有元素的话，返回 true。
emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
*/
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>q;//创建队列q
	q.push(1);//1入队
	q.push(2);//2入队
	q.push(3);//3入队
	q.push(4);//4入队
	if (q.empty())//如果队列是空的那就返回true
	{
		cout << "队列为空，";
		return 0;
	}
	cout << "这个队列长度为" << q.size() << "，";
	cout << "读取到的队尾元素为" << q.back() << ",";
	cout << "读取到的队首元素为" << q.front() << "。" << endl;
	while (q.empty() != true)//如果队列不为空就进入，循环直到队列为空为止
	{
		cout << q.front() << " ";//输出队首元素数据
		q.pop();//出队队首元素
	}
	cout << endl;
	return 0;
}