//http://icpc.me/1260
#include <bits/stdc++.h>

using namespace std;

int dfs(int, int);

int arr[101][101]; 
bool is_visited[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin>>n>>m;
	while (m--) {
		int i, j;
		cin>>i>>j;
		arr[i][j]=arr[j][i]=1;
	}
	cout << dfs(n,1);

	return 0;
}

int dfs(int n, int v)
{
	static int cnt = 0;

	is_visited[v]=true;
	for (int i = 1; i<=n; ++i) {
		if (is_visited[i]) {
			continue;
		}
		if (!arr[v][i]) {
			continue;
		}
		++cnt;
		dfs(n,i);
	}

	return cnt;
}