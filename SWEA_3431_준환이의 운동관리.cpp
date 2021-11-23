#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int L, U, X;
		int answer = 0;
		cin >> L >> U >> X;

		if (L - X > 0)
		{
			answer = L-X;
		}
		else if (L <= X and X <= U)
		{
			answer = 0;
		}
		else if (X - U > 0)
		{
			answer = -1;
		}

		cout << '#' << i + 1 << ' ' << answer << endl;
	}
	return 0;
}