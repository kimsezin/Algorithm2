#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int alphabet[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main()
{
	string her_name;
	string his_name;

	cin >> his_name >> her_name;
	vector<int> couple;
	for (int i = 0; i < his_name.size(); i++)
	{
		couple.push_back(alphabet[his_name[i] - 'A']);
		couple.push_back(alphabet[her_name[i] - 'A']);
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