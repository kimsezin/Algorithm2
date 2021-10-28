#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
		{
			size_t found = temp.find(temp[j]);
			found = temp.find(temp[j], found + 1);
			if (found!=string::npos)
			{				
				temp.erase(temp.find(temp[j]),1);
				temp.erase(found-1,1);
				j--;
			}
		}

		if (temp == "")
		{
			cout << '#' << i << ' ' << "Good" << endl;
		}
		else
		{
			sort(temp.begin(), temp.end());
			cout << '#' << i << ' ' << temp << endl;
		}

	}
}