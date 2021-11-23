#include<iostream>
#include<algorithm>

using namespace std;
int fibo[21];
int main()
{
	fibo[0] = 0;
	fibo[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n] * 2 + (fibo[n] + fibo[n - 1]) * 2;
	return 0;
}