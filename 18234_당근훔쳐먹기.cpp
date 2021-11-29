#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

long long N, T;
vector<long long> P_list;




int main() {
	long long answer = 0;
	cin >> N >> T;

	for (int i = 0; i < N; i++)
	{
		int w, p;
		cin >> w >> p;

		P_list.push_back(p);
		answer += w;
	}

	sort(P_list.begin(), P_list.end());
	for (int i = 0; i < N; i++)
	{
		answer += P_list[N - 1 - i] * (T - 1 - i);
	}
	cout << answer;
}