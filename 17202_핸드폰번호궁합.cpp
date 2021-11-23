#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	vector<int> couple;
	for (int i = 0; i < A.size(); i++)
	{
		couple.push_back(A[i] - '0');
		couple.push_back(B[i] - '0');
	}

	while (couple.size() != 2)
	{
		vector<int> temp;
		for (int i = 0; i < couple.size()-1; i++)
		{
			temp.push_back((couple[i] + couple[i + 1])%10);
		}
		couple = temp;
	}

	cout << couple[0] << couple[1];
	return 0;
}