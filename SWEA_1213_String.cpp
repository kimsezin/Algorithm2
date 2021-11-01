#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int t;
		cin >> t;

		string target,input;
		cin >> target;
		cin >> input;

		int target_length = target.length();
		int cnt = 0;
		for (int i = 0; i < input.length() - target.length() + 1; i++)
		{
			string temp = input.substr(i, target.length());
			if (temp == target)
			{
				cnt++;
			}
		}
		
		cout << '#' << i << ' ' << cnt << endl;
		
	}
	return 0;
}