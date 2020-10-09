#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long *a=new long long[n];
	a[0] = 0, a[1] = 1;
	//直接使用迭代这样的话时间复杂度为O(n)，这样的话不会超时，但是如果n大的话，空间复杂度会更大，以空间换时间
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % 10007;
	}
	cout << a[n] << endl;
	return 0;
}