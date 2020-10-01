#include<iostream>
using namespace std;
bool BinarySearch(int* array, int top, int base, int answer, int& area)//分别储存的是需要查询的数组、正在被查询的部分的上标、正在被查询的部分的下标、需要查找的数据、如果查到数据存在后存位置用的
{
	bool key;//储存状态，如果查到了想要查的数据将在接下来的代码中赋值为true，否则赋值为false
	int middle = (top + base) / 2;//算出正在被查询的部分的上标和正在被查询的部分的下标中间的那个值，将这个要被查询的数组一分为二来查询
	if (top - base > 1)//如果正在被查询的部分的数组元素个数大于1，那么进入这个循环
	{
		if (array[middle] == answer)//如果正在被查询的部分的中间的那个值正好是我们要查的值
		{
			area = middle;//将middle赋值给area，这里的area是从main中引用过来的，这样main函数里的area就会收到所查到的数在数组中的位置
			return true;//返回true给调用这个函数的key表明查到了这个数值在数组中所在的位置，如果是main里调用的函数（不是递归进入的）那么就返回给main里调用它的地方一个true
		}
		else//如果数组middle下标所拥有的那个值并不是我们想要查询的，那么继续将正在被查询的部分拆成两半来查询
		{
			if (array[middle] > answer)//如果查询的数小于数组middle下标所拥有的那个值
			{
				key = BinarySearch(&array[0], middle, base, answer, area);//用递归的方法查询这个正在被查询的部分的前半部分
			}
			else//如果查询的数大于数组middle下标所拥有的那个值
			{
				key = BinarySearch(&array[0], top, middle, answer, area);//用递归的方法查询这个正在被查询的部分的后半部分
			}
		}
	}
	else//如果正在被查询的部分只有两个元素，那么只需看这两个元素是不是我们想查的元素
	{
		if (array[top] == answer)//如果正在被查询的部分上标所对应位置上的值就是我们想要查的元素
		{
			area = top;//将上标赋值给area，这里的area是从main中引用过来的，意思就是告诉main中的area我们要查询的值在这个数组的哪个位置
			return true;//返回true给调用这个函数的key表明查到了这个数值在数组中所在的位置，如果是main里调用的函数（不是递归进入的）那么就返回给main里调用它的地方一个true
		}
		else
		{
			if (array[base] == answer)//如果正在被查询的部分下标所对应位置上的值就是我们想要查的元素
			{
				area = base;//将下标赋值给area，这里的area是从main中引用过来的，意思就是告诉main中的area我们要查询的值在这个数组的哪个位置
				return true;//返回true给调用这个函数的key表明查到了这个数值在数组中所在的位置，如果是main里调用的函数（不是递归进入的）那么就返回给main里调用它的地方一个true
			}
			else
			{
				return false;//返回false给调用这个函数的key表明查到了这个数值在数组中所在的位置，如果是main里调用的函数（不是递归进入的）那么就返回给main里调用它的地方一个true
			}
		}
	}
	return key;//返回key的值给调用这个函数的key表明是否查到了这个数值在数组中所在的位置，如果现在是main里调用的函数（不是递归进入的）那么就返回给main里调用它的地方一个key的值
}
int main()
{
	int array[10] = { 2,11,23,31,41,53,61,71,83,127 };
	int top = sizeof(array) / sizeof(int) - 1;
	int base = 0;
	int area;
	int answer;
	cout << "请输入要查找的数：";
	cin >> answer;
	if (BinarySearch(&array[0], top, base, answer, area))
	{
		cout << "结果已找到，在数组下标（从0开始）为" << area << "的位置。" << endl;
	}
	else
	{
		cout << "结果未找到。" << endl;
	}
	return 0;
}