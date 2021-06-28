// https://www.acmicpc.net/problem/15558
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static bool arr[2][100'001];
	static bool is_visited[2][100'001];

	int n, k;
	cin>>n>>k;
	for (int i = 0; i<2; ++i) {
		string str;
		cin>>str;

		int j = 1;
		for (char c : str) {
			arr[i][j++]=c-'0';
		}
	}
	const pair<int, int> jump_to[3] = {
		{0,1},
		{0,-1},
		{1,k}
	};
	queue<pair<int, int>> q;
	q.push({0,1});
	is_visited[0][1]=true;
	int time = 1;
	bool is_clear = false;
	while (!q.empty() && !is_clear) {
		int cnt = q.size();
		while (cnt--) {
			auto cur = q.front();
			q.pop();

			if (time>cur.second) {
				continue;
			}
			for (int d = 0; d<3; ++d) {
				int x = (cur.first+jump_to[d].first)%2; // 0->1, 1->0
				int y = cur.second+jump_to[d].second;
				
				if (y<1) {
					continue;
				}
				if (!arr[x][y] || is_visited[x][y]) {
					continue;
				}
				if (y>n) {
					is_clear=true;
					break;
				}
				q.push({x,y});
				is_visited[x][y]=true;
			}
			if (is_clear) {
				break;
			}
		}
		++time;
	}
	cout << ((is_clear) ? 1 : 0);

    return 0;
}