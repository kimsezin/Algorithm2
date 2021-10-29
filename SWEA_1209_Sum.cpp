#include<iostream>
#include<vector>

using namespace std;

int board[100][100];
int max_value = 0;
void init()
{
	max_value = 0;
	for (int i = 0; i < 100; i++)
	{
		int sum = 0;
		for (int j = 0; j < 100; j++)
		{
			cin >> board[i][j];
			sum += board[i][j];
		}
		max_value = max(sum, max_value);
	}
}
void solve()
{
	for (int i = 0; i < 100; i++)
	{
		int col_sum=0;
		int row_sum = 0;
		for (int j = 0; j < 100; j++)
		{
			col_sum += board[j][i];
		}
		max_value = max(col_sum, max_value);
	}
	int sum = 0;
	int sum_left=0;
	
	for (int i = 0; i < 100; i++)
	{
		sum += board[i][i];
		sum_left += board[i][99-i];
	}
	max_value = max(sum, max_value);
	max_value = max(sum_left, max_value);
}
int main()
{
	
	for (int i = 1; i <= 10; i++)
	{
		init();
		
		solve();

		cout << '#' << i << ' ' << max_value << endl;
	}
	return 0;
}