/*
ע�⣺�������������������㷨����������֮���ٿ�������
*/
#include<iostream>
using namespace std;
typedef int Elemtype;
typedef struct
{
	Elemtype* elem;//������
	int length;//���鳤��
}SqList;
void InitList(SqList& L)//���������
{
	cin >> L.length;//�������鳤��
	L.elem = new Elemtype[L.length + 1];//���ɶ�
	for (int i = 1; i <= L.length; i++)
	{
		cin >> L.elem[i];//��������
	}
}
int Partition(SqList& L, int low, int high)//ɸѡ����
{
	L.elem[0] = L.elem[low];//�Ȱѵ�λ���ָ����±�Ϊ0��Ԫ�أ��ڽ������Ĵ����н���Ϊ�����ɸѡ��������ͱ���С����
	while (low < high)//ֻҪlow��highû���������ͼ���ѭ��
	{
		while (low < high && L.elem[high] >= L.elem[0])//���low��highû����������highλ���ϵ�����0λ���ϵ����󣬾���high��λ����low�����ƶ�
		{
			--high;
		}
		L.elem[low] = L.elem[high];//������highλ���ϵ�����0λ���ϵ���С����ô�Ͱ����������lowλ���ϣ�lowλ���ϵ����Ѿ�����0λ�û����Ѿ�������һ����highλ�ã����õ��ĸ������⣩
		while (low < high && L.elem[low] <= L.elem[0])//���low��highû����������lowλ���ϵ�����0λ���ϵ���С������low��λ����high�����ƶ�
		{
			++low;
		}
		L.elem[high] = L.elem[low];//������lowλ���ϵ�����0λ���ϵ�������ô�Ͱ����������highλ���ϣ�highλ���ϵ����Ѿ�������һ����lowλ�ã����õ��ĸ������⣩
	}
	L.elem[low] = L.elem[0];//����0λ��С��������������ĵ�λ�࣬��0���������������ĸ�λ�࣬��ô0λ���ϵ�������lowλ���ϣ������ڱ�lowС��������low�ĵ�λ�ߣ���low���������low�ĸ�λ��
	return low;//����low
}
void QSort(SqList& L, int low, int high)//���������㷨����ͨ��ɸѡ�����ҳ�һ����ˣ�Ȼ�������ֳɱȱ��λ���ϵ���С��һ���ֺͱȱ��λ���ϵ������һ���֣�����Щ�����ټ����ұ�˺ͷֲ���
{
	if (low < high)//���low��highС�������Ŀ���ǵ�ֻ��һλ��ʱû��Ҫ�Ƚ�ʱ������if�õģ�
	{
		int pivotloc = Partition(L, low, high);//����ɸѡ��������ɸѡ�����з�������ֵ����pivotloc��ÿһ��ɸѡ��������󣬾�ȷ����ĳһֵ�������е�λ�ã�
		//��ʱ�γ�����pivotlocΪ���ޣ���λ����ȫ�Ǳ�pivotlocλ���ϵ���С��������λ����ȫ�Ǳ�pivotlocλ���ϵ��������
		QSort(L, low, pivotloc - 1);//����pivotlocλ������С���ⲿ��������һ����������㷨
		QSort(L, pivotloc + 1, high);//����pivotlocλ����������ⲿ��������һ����������㷨
	}
}
void Display(SqList& L)//��ʾ����õ�
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