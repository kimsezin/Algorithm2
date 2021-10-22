#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int min_value = 101;
		int max_value = 0;

		int N;
		cin >> N;
		vector<int> values;
		for(int j=0;j<100;j++)
		{
			int temp;
			cin >> temp;
			values.push_back(temp);
		}
		sort(values.begin(), values.end());

		for (int k = 0; k < N; k++)
		{
			values[0]++;
			values[values.size() - 1]--;
			sort(values.begin(), values.end());
		}

		cout << '#' << i << ' ' << values[values.size() - 1] - values[0] << '\n';
	}
}