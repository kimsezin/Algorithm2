#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[4][9];
int C_map[4][9];
int space = 0;
vector<pair<int, int>> Empty, Virus;
bool check[65];
bool visit[4][9];
int N, M;
int answer = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void copy_map()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			C_map[i][j] = map[i][j];
		}
	}
}

void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M)
			{
				if (visit[nx][ny] == false && C_map[nx][ny] == 0)
				{
					C_map[nx][ny] = 2;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int count_zero()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (C_map[i][j] == 0) cnt++;
		}
	}

	return cnt;
}
void Spread_virus()
{
	int cnt = 0;
	copy_map();
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < space; i++)
	{
		if (cnt == 3)
			break;
		if (check[i] == true)
		{
			int nx = Empty[i].first;
			int ny = Empty[i].second;
			C_map[nx][ny] = 1;
			cnt++;
		}
	}

	for (int i = 0; i < Virus.size(); i++)
	{
		int nx = Virus[i].first;
		int ny = Virus[i].second;
		bfs(nx, ny);
	}

	int zero_cnt = count_zero();
	answer = max(answer, zero_cnt);
}
void make_wall(int idx, int cnt)
{
	if (cnt == 3)
	{
		Spread_virus();
		return;
	}
	
	for (int i = idx; i < space; i++)
	{
		if (check[i] == true)
			continue;

		check[i] = true;
		make_wall(i, cnt + 1);
		check[i] = false;
	}
}
int main()
{
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 0)
				Empty.push_back({ i,j });
			else if (temp == 2)
				Virus.push_back({ i,j });

			map[i][j] = temp;
		}
	}
	space = Empty.size();

	make_wall(0, 0);

	cout << answer;
	return 0;
}