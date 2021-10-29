#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;
char board[8][8];
int cnt = 0;
void solve()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <= 8 - N; j++)
		{
			string temp = "";
			for (int k = 0; k < N; k++)
			{
				temp += board[i][j + k];
			}

			string front=temp.substr(0,N/2) ,end;

			if (N % 2 == 0)
			{
				end = temp.substr(N / 2, N / 2);
			}
			else
			{
				end = temp.substr(N / 2 + 1, N / 2);
			}
			reverse(end.begin(), end.end());
			if (front == end)
			{
				cnt++;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <= 8 - N; j++)
		{
			string temp = "";
			for (int k = 0; k < N; k++)
			{
				temp += board[j + k][i];
			}

			string front = temp.substr(0, N / 2), end;

			if (N % 2 == 0)
			{
				end = temp.substr(N / 2, N / 2);
			}
			else
			{
				end = temp.substr(N / 2 + 1, N / 2);
			
			}
			reverse(end.begin(), end.end());
			if (front == end)
			{
				cnt++;
			}
		}
	}
}
void init()
{
	cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> board[i][j];
		}
	}
}
int main()
{
	
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		cin >> N;
		init();
		solve();
	
		cout << '#' << test_case << ' ' << cnt << endl;
	}
	
	return 0;
}