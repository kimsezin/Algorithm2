#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string temp = "A";

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		string next;
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == 'A')
			{
				next += "B";
			}
			else
			{
				next += "BA";
			}
		}
		temp = next;
	}

	int a_cnt = 0, b_cnt = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 'A')
		{
			a_cnt++;
		}
		else
		{
			b_cnt++;
		}
	}
	cout << a_cnt << ' ' << b_cnt;

	return 0;
}