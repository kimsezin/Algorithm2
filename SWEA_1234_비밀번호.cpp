#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int length;
		cin >> length;

		string input;
		cin >> input;

		for (int i = 1; i < input.size(); i++)
		{
			if (input[i] == input[i - 1])
			{
				input.erase(input.begin() + i);
				input.erase(input.begin() + i - 1);
				i-=2;
			}
		}
		
		cout << '#' << t << ' ' << input << endl;
	}
	return 0;
}