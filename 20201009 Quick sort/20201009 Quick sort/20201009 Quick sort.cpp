/*
注意：请先自行理解快速排序算法是如何排序的之后再看本代码
*/
#include<iostream>
using namespace std;
typedef int Elemtype;
typedef struct
{
	Elemtype* elem;//数据域
	int length;//数组长度
}SqList;
void InitList(SqList& L)//创建数组堆
{
	cin >> L.length;//输入数组长度
	L.elem = new Elemtype[L.length + 1];//生成堆
	for (int i = 1; i <= L.length; i++)
	{
		cin >> L.elem[i];//输入数据
	}
}
int Partition(SqList& L, int low, int high)//筛选工作
{
	L.elem[0] = L.elem[low];//先把低位数字赋给下表为0的元素，在接下来的代码中将作为标杆来筛选出比它大和比它小的数
	while (low < high)//只要low和high没有相遇，就继续循环
	{
		while (low < high && L.elem[high] >= L.elem[0])//如果low和high没有相遇并且high位置上的数比0位置上的数大，就让high的位置往low方向移动
		{
			--high;
		}
		L.elem[low] = L.elem[high];//当遇到high位置上的数比0位置上的数小，那么就把这个数放在low位置上（low位置上的数已经给了0位置或者已经给了上一步的high位置，不用担心覆盖问题）
		while (low < high && L.elem[low] <= L.elem[0])//如果low和high没有相遇并且low位置上的数比0位置上的数小，就让low的位置往high方向移动
		{
			++low;
		}
		L.elem[high] = L.elem[low];//当遇到low位置上的数比0位置上的数大，那么就把这个数放在high位置上（high位置上的数已经给了上一步的low位置，不用担心覆盖问题）
	}
	L.elem[low] = L.elem[0];//当比0位置小的数放在了数组的低位侧，比0大的数放在了数组的高位侧，那么0位置上的数放在low位置上，这样在比low小的数都在low的低位边，比low大的数都在low的高位边
	return low;//返回low
}
void QSort(SqList& L, int low, int high)//快速排序算法，先通过筛选工作找出一个标杆，然后把数组分成比标杆位置上的数小的一部分和比标杆位置上的数大的一部分，把这些部分再继续找标杆和分部分
{
	if (low < high)//如果low比high小（这里的目的是当只有一位数时没必要比较时不进入if用的）
	{
		int pivotloc = Partition(L, low, high);//进入筛选工作并把筛选工作中返回来的值赋给pivotloc（每一次筛选工作做完后，就确定了某一值在排序中的位置）
		//这时形成了以pivotloc为界限，低位方向全是比pivotloc位置上的数小的数，高位方向全是比pivotloc位置上的数大的数
		QSort(L, low, pivotloc - 1);//将比pivotloc位置上数小的这部分数进下一层快速排序算法
		QSort(L, pivotloc + 1, high);//将比pivotloc位置上数大的这部分数进下一层快速排序算法
	}
}
void Display(SqList& L)//显示结果用的
{
	for (int i = 1; i <= L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}
int main()
{
	SqList L;
	InitList(L);
	QSort(L, 1, L.length);
	Display(L);
	return 0;
}