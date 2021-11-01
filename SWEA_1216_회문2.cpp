#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char board[100][100];

void init()
{
	int N; cin >> N;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cin >> board[i][j];
		}
	}
}
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		init();
		int idx = 0;
		for (int row = 0; row < 100; row++)
		{
			for (int j = 100; j > 0; j--)
			{
				int length = 100 - idx;

				string temp = "";
				for (int start = 0; start <= idx; start++)
				{
					for (int num = start; num < length + start; num++)
					{
						temp += board[row][num];

						string front = "", end = "";
						if (temp.length() % 2 == 0)
						{
							front = temp.substr(0, temp.length() / 2 - 1);
							end = temp.substr(temp.length() / 2, temp.length() - 1);
						}
						else
						{
							front = temp.substr(0, temp.length() / 2 - 1);
							end = temp.substr(temp.length() / 2 + 1, temp.length() - 1);
						}

						if (front == end)
						{
							cout << '#' << i << ' ' << j << endl;
						}
					}
				}
				idx++;
			}
			idx = 0;
		}

		idx = 0;
		for (int row = 0; row < 100; row++)
		{
			for (int j = 100; j > 0; j--)
			{
				int length = 100 - idx;

				string temp = "";
				for (int start = 0; start <= idx; start++)
				{
					for (int num = start; num < length + start; num++)
					{
						temp += board[num][row];

						string front = "", end = "";
						if (temp.length() % 2 == 0)
						{
							front = temp.substr(0, temp.length() / 2 - 1);
							end = temp.substr(temp.length() / 2, temp.length() - 1);
						}
						else
						{
							front = temp.substr(0, temp.length() / 2 - 1);
							end = temp.substr(temp.length() / 2 + 1, temp.length() - 1);
						}

						if (front == end)
						{
							cout << '#' << i << ' ' << j << endl;
						}
					}
				}
				idx++;
			}
			idx = 0;
		}
	}

	return 0;
}