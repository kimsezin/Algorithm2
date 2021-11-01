#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string temp;
		cin >> temp;
		int cnt = 0;
		string start = "";
		for (int j = 0; j < temp.size(); j++)
		{
			start += '0';
		}
		for (int k = 0; k < temp.size(); k++)
		{
			if (start[k] == temp[k])
				continue;
			else
			{
				char temp_alpha = temp[k];
				for (int z = k; z < temp.size(); z++)
				{
					start[z] = temp_alpha;
				}
				cnt++;
			}
		}

		cout << '#' << i << ' ' << cnt << endl;

	}

	return 0;
}