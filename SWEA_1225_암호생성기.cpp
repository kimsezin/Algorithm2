#include<iostream>
#include<vector>

using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int N;
		cin >> N;
		vector<int> input;
		for (int j = 0; j < 8; j++)
		{
			int temp;
			cin >> temp;
			input.push_back(temp);
		}

		int idx = 1;
		while (1)
		{
			int temp = input[0];
			input.erase(input.begin());
			temp -= idx;
			if (temp <= 0)
			{
				input.push_back(0);
				break;
			}
			else
			{
				input.push_back(temp);
			}
			idx++;

			if (idx == 6)
			{
				idx = 1;
			}
		}
		
		cout << '#' << i << ' ';
		for (int i = 0; i < input.size(); i++)
		{
			cout << input[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}