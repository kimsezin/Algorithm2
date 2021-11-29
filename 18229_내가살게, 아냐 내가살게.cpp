#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int input[100][100];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;
			input[i][j] = temp;
		}
	}
	int result[100];
	memset(result, 0, 100);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[j] += input[j][i];
			if (result[j] >= K)
			{
				cout << j + 1 << ' ' << i + 1;
				return 0;
			}
		}
	}
	return 0;
}