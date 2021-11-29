#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

bool visited[300001];
vector<int> teleport[300001];
queue<pair<int, int>> q;
int N, M, S, E;

void bfs(int start)
{
	q.push({ start,0 });
	visited[start] = true;

	while (!q.empty())
	{
		int n_start = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (n_start == E)
		{
			cout << cnt ;
			return;
		}

		if (n_start > 1 && visited[n_start-1] == false)
		{
			q.push({ n_start - 1,cnt + 1 });
			visited[n_start - 1] = true;
		}
		if (n_start < N && visited[n_start+1] == false)
		{
			q.push({ n_start + 1,cnt + 1 });
			visited[n_start + 1] = true;
		}

		for (int i = 0; i < teleport[n_start].size(); i++)
		{
			if (visited[teleport[n_start][i]] == false)
			{
				q.push({ teleport[n_start][i],cnt + 1 });
				visited[teleport[n_start][i]] = true;
			}
		}
	}


}
int main()
{
	
	cin >> N >> M;
	cin >> S >> E;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		teleport[A].push_back(B);
		teleport[B].push_back(A);
	}

	bfs(S);
}