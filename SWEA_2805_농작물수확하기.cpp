#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdio.h>
int map[50][50];
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	for (int T = 1; T <= test_case; T++)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			for (int j = 0; j < temp.size(); j++)
			{
				map[i][j] = temp[j] - '0';
			}


		}
		int sum = 0;
		
		int num =0;
		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			sum += map[N / 2][i];
			for (int j = 1; j <= num; j++)
			{
				sum += map[N / 2 + j][i];
				sum += map[N / 2 - j][i];
			}
			if (flag==true)
			{
				if (num == N / 2)
				{
					flag = false;
					num--;
					continue;
				}
				num++;
				
			}
			else
			{
				num--;
			}
		}


		cout << '#' << T << ' ' << sum << endl;
	}
}