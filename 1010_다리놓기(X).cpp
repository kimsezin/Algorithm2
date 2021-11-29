#include<iostream>
#include<algorithm>

using namespace std;
int dp[31][31];
int main()
{
	int T;
	for (int i = 1; i < 31; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;

		for (int j = 2; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				dp[j][k] = dp[j-1]
			}
		}
	}

	return 0;
}