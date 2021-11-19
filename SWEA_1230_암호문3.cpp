#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	for (int test_case = 1; test_case < 11; test_case++)
	{
		int cnt;
		cin >> cnt;
		vector<int> input;
		for (int i = 0; i < cnt; i++)
		{
			int temp;
			cin >> temp;
			input.push_back(temp);
		}

		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			char function;
			cin >> function;

			if (function == 'I')
			{
				int index;
				cin >> index;

				int num;
				cin >> num;

				for (int j = 0; j < num; j++)
				{
					int temp;
					cin >> temp;
					input.insert(input.begin() + index + j, temp);
				}
			}

			if (function == 'D')
			{
				int index;
				cin >> index;

				int num;
				cin >> num;

				for (int i = 0; i < num; i++)
				{
					input.erase(input.begin()+index);
				}
			}

			if (function == 'A')
			{
				int num;
				cin >> num;

				for (int i = 0; i < num; i++)
				{
					int temp;
					cin >> temp;
					input.push_back(temp);
				}
			}
			
			cout << '#' << test_case << ' ';
			for (int i = 0; i < input.size(); i++)
			{
				cout << input[i] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}