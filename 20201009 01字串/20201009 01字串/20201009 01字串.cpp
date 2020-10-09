/*
问题描述:
对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：
00000
00001
00010
00011
00100
请按从小到大的顺序输出这32种01串。

输出格式
输出32行，按从小到大的顺序每行一个长度为5的01串。
*/

#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i <= 31; i++)//从0(00000B)开始到31(11111B)结束
	{
		int temp = i, array[5];//用temp记录i的值，方便下面运算；用array数组记录二进制位
		for (int j = 4; j >= 0; j--)//按照十进制转二进制手算方法，从低位到高位计算二进制
		{
			array[j] = temp % 2;//手算方法中的取余数工作
			temp /= 2;//手算方法中的除以2的工作
		}
		for (int j = 0; j <= 4; j++)//输出二进制
		{
			cout << array[j];//一个位一个位的输出二进制
		}
		cout << endl;//换行
	}
	return 0;
}