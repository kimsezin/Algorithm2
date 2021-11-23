#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> m;

bool cmp(string a, string b)
{
	if (m[a] > m[b])
		return a < b;
	else
		return a > b;
}
map<int, string> m1;
int main()
{
	m["ZRO"] = 0;
	m["ONE"] = 0;
	m["TWO"] = 0;
	m["THR"] = 0;
	m["FOR"] = 0;
	m["FIV"] = 0;
	m["SIX"] = 0;
	m["SVN"] = 0;
	m["EGT"] = 0;
	m["NIN"] = 0;

	m1[0] = "ZRO";
	m1[1] = "ONE";
	m1[2] = "TWO";
	m1[3] = "THR";
	m1[4] = "FOR";
	m1[5] = "FIV";
	m1[6] = "SIX";
	m1[7] = "SVN";
	m1[8] = "EGT";
	m1[9] = "NIN"; 

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string test_case;
		cin >> test_case;

		int num;
		cin >> num;
		vector<pair<string,int>> input;
		string temp;
		for (int i = 0; i < num; i++)
		{
			cin >> temp;
			m[temp]++;
		}

		cout << test_case << endl;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < m[m1[i]]; j++)
			{
				cout << m1[i] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}