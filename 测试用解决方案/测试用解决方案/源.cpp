#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long *a=new long long[n];
	a[0] = 0, a[1] = 1;
	//ֱ��ʹ�õ��������Ļ�ʱ�临�Ӷ�ΪO(n)�������Ļ����ᳬʱ���������n��Ļ����ռ临�ӶȻ�����Կռ任ʱ��
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % 10007;
	}
	cout << a[n] << endl;
	return 0;
}