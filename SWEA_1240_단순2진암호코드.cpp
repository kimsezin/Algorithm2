#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>


using namespace std;




int main()
{
	map<int, string> m;

	m[0] = "0001101";
	m[1] = "0011001";
	m[2] = "0010011";
	m[3] = "0111101";
	m[4] = "0100011";
	m[5] = "0110001";
	m[6] = "0101111";
	m[7] = "0111011";
	m[8] = "0110111";
	m[9] = "0001011";


	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int x, y;
		cin >> x >> y;

		string input;
		cin >> input;
		int num=10;
		int result = 0;
		int cnt = 0;
		vector<int> code;
		for (int j = 0; j < input.size(); j++)
		{
			for (int c = 0; c < y; c++)
			{
				string temp = input.substr(j, 7);

				for (int k = 0; k < 10; k++)
				{
					if (temp == m[k])
					{
						code.push_back(k);
						j += 6;
						cnt++;
						break;
					}
				}
				if (cnt == 8)
				{
					break;
				}
			}
		}

		int right_code = ((code[0] + code[2] + code[4] + code[6]) * 3 + (code[1] + code[3] + code[5]) + code[7]);
		if (right_code % 10 == 0)
		{
			int sum = 0;
			for (int j = 0; j < 8; j++)
			{
				sum += code[j];
			}
			cout << '#' << i + 1 << ' ' << sum << '\n';
		}
		else
		{
			cout << '#' << i + 1 << ' ' << 0 << '\n';
		}
	}

}