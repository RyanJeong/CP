//http://icpc.me/1260
#include <bits/stdc++.h>

using namespace std;

void dfs(int, int);
void bfs(int, int);

int arr[1001][1001]; 
bool is_visited[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m, v;
	cin>>n>>m>>v;
	for (int i = 1; i<=m; ++i) {
		int x, y;
		cin>>x>>y;
		arr[x][y]=arr[y][x]=1;
	}

	dfs(n,v);
	cout << '\n';
	memset(is_visited,false,sizeof is_visited);
	bfs(n,v);

	return 0;
}

void dfs(int n, int v)
{
	is_visited[v]=true;
	cout << v << ' ';
	for (int i = 1; i<=n; ++i) {
		if (is_visited[i]) {
			continue;
		}
		if (!arr[v][i]) {
			continue;
		}
		dfs(n,i);
	}

	return;
}

void bfs(int n, int v)
{
	queue<int> q;
	q.push(v);
	is_visited[v]=true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		cout << cur << ' ';
		for (int i = 1; i<=n; ++i) {
			if (is_visited[i]) {
				continue;
			}
			if (!arr[cur][i]) {
				continue;
			}
			q.push(i);
			is_visited[i]=true;
		}
	}

	return;
}