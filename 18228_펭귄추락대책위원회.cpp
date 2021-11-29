#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> input;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			idx = i;
		input.push_back(temp);
	}

	int front_value=1000000001, last_value = 1000000001;

	for (int i = 0; i < idx; i++)
	{
		if (front_value > input[i])
			front_value = input[i];
		
	}
	for (int i = input.size() - 1; i > idx; i--)
	{
		if (last_value > input[i])
			last_value = input[i];
	}

	cout << front_value + last_value;

	return 0;
}