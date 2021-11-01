#include<iostream>
#include<algorithm>


using namespace std;


int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int temp;
		cin >> temp;

		int num, cnt;
		cin >> num >> cnt;

		int result = num;
		for (int j = 1; j < cnt; j++)
		{
			result = result * num;
		}
	}
	return 0;
}