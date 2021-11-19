#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{

	int T;
	cin >> T;

	int N, L;
	cin >> N >> L;

	int dp[21][10001];
	int w[21], v[21];
	for (int i = 1; i <= N; i++)
	{
		int num, cal;
		cin >> v[i] >> w[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			if (w[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = v[i] + dp[i - 1][j - w[i]] > dp[i - 1][j] ? v[i] + dp[i - 1][j - w[i]] : dp[i - 1][j];
			}
		}
	}


}