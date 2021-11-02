#include<iostream>
#include<vector>

using namespace std;

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int N;
		cin >> N;
		vector<int> password;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			password.push_back(temp);
		}

		int command_cnt;
		cin >> command_cnt;
		for (int i = 0; i < command_cnt; i++)
		{
			char insert;
			cin >> insert;

			int x, y;
			vector<int> push;
			cin >> x >> y;
			for (int j = 0; j < y; j++)
			{
				int temp;
				cin >> temp;
				password.insert(password.begin() + x + j, temp);
			}
		}
		cout << '#' << t << ' ';
		for (int i = 0; i < 10; i++)
			cout << password[i] << ' ';

		cout << endl;
	}
	return 0;
}