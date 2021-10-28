#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int answer = 0;
int N;
int row, col;
char board[1000][1000];
int dist[1000][1000];
vector<pair<int, int>> water;
queue<pair<int, int>> q;

void init()
{
	water.clear();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			dist[i][j] = 0;
			cin >> board[i][j];
			if (board[i][j] == 'W')
				water.push_back({ i,j });
		}
	}
}
int solve()
{
	for (int i = 0; i < water.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nx = water[i].first + dx[j];
			int ny = water[i].second + dy[j];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col)
			{
				if (board[nx][ny] == 'L')
				{
					dist[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	while (!q.empty())
	{
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col)
			{
				if (board[nx][ny] == 'W')
					continue;
				if (dist[nx][ny] == 0)
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
				else
				{
					if (dist[nx][ny] > dist[x][y] + 1)
					{
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny });
					}
					else
					{
						continue;
					}
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'L')
				cnt += dist[i][j];
		}
	}
	return cnt;
}
int main()
{
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> row >> col;
		init();
		int cnt = solve();
		
		cout << '#' << i + 1 << ' ' << cnt << endl;
	}

	
	return 0;
}