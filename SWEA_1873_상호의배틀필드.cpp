#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int width, height;
char map[3][21];
void pr()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	//cout << endl;
}
int main()
{
	int test_case;
	cin >> test_case;

	for (int T = 0; T < test_case; T++)
	{
		
		cin >> height >> width;

		
		
		int tank_x_idx = 0;
		int tank_y_idx = 0;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				char temp;
				cin >> temp;
				map[i][j] = temp;

				if (temp == '<' or temp == '^' or temp == 'v' or temp == '>')
					tank_x_idx = i, tank_y_idx = j;
			}
		}

		int N;
		cin >> N;

		string input;
		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == 'U')
			{
				map[tank_x_idx][tank_y_idx] = '^';
				if (tank_x_idx - 1 >= 0)
				{
					if (map[tank_x_idx - 1][tank_y_idx] == '.')
					{
						tank_x_idx -= 1;
						map[tank_x_idx][tank_y_idx] = '^';
						map[tank_x_idx+1][tank_y_idx] = '.';
					}
				}
				//pr();
			}

			else if (input[i] == 'D')
			{
				map[tank_x_idx][tank_y_idx] = 'v';
				if (tank_x_idx +1 < height)
				{
					if (map[tank_x_idx+1][tank_y_idx] == '.')
					{
						tank_x_idx += 1;
						map[tank_x_idx][tank_y_idx] = 'v';
						map[tank_x_idx - 1][tank_y_idx] = '.';
					}
				}
				//pr();
			}

			else if (input[i] == 'L')
			{
				map[tank_x_idx][tank_y_idx] = '<';
				if (tank_y_idx - 1 >= 0)
				{
					if (map[tank_x_idx][tank_y_idx-1] == '.')
					{
						tank_y_idx -= 1;
						map[tank_x_idx][tank_y_idx] = '<';
						map[tank_x_idx][tank_y_idx+1] = '.';
					}
				}
				//pr();
			}

			else if (input[i] == 'R')
			{
				map[tank_x_idx][tank_y_idx] = '>';
				if (tank_y_idx + 1 < width)
				{
					if (map[tank_x_idx][tank_y_idx+1] == '.')
					{
						tank_y_idx += 1;
						map[tank_x_idx][tank_y_idx] = '>';
						map[tank_x_idx][tank_y_idx-1] = '.';
					}
				}
				//pr();
			}

			else if (input[i] == 'S')
			{
				if (map[tank_x_idx][tank_y_idx] == '<')
				{
					for (int i = tank_y_idx-1; i >= 0; i--)
					{
						if (map[tank_x_idx][i] == '*')
						{
							map[tank_x_idx][i] = '.';
							break;
						}
						else if (map[tank_x_idx][i] == '#')
						{
							break;
						}
					}
				}

				else if (map[tank_x_idx][tank_y_idx] == '>')
				{
					for (int i = tank_y_idx+1; i <width; i++)
					{
						if (map[tank_x_idx][i] == '*')
						{
							map[tank_x_idx][i] = '.';
							break;
						}
						else if (map[tank_x_idx][i] == '#')
						{
							break;
						}
					}
				}

				else if (map[tank_x_idx][tank_y_idx] == '^')
				{
					for (int i = tank_x_idx-1; i >=0; i--)
					{
						if (map[i][tank_y_idx] == '*')
						{
							map[i][tank_y_idx] = '.';
							break;
						}
						else if (map[i][tank_y_idx] == '#')
						{
							break;
						}
					}
				}

				else if (map[tank_x_idx][tank_y_idx] == 'v')
				{
					for (int i = tank_x_idx + 1; i < height; i++)
					{
						if (map[i][tank_y_idx] == '*')
						{
							map[i][tank_y_idx] = '.';
							break;
						}
						else if (map[i][tank_y_idx] == '#')
						{
							break;
						}
					}
				}
			}
			//pr();
		}

		cout << '#' << T+1 << ' ';
		pr();
	}
	return 0;
}

