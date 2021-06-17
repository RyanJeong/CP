//http://icpc.me/1987
#include <bits/stdc++.h>

using namespace std;

int dfs(int, int); // r, c, movement

char arr[21][21]; // 1 ~ 20
bool is_visited['Z'-'A'+1]; // 0 ~ 'Z'-1
int r, c;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>r>>c;
	for (int i = 1; i<=r; ++i) {
		for (int j = 1; j<=c; ++j) {
			cin>>arr[i][j];
		}
	}

	is_visited[arr[1][1]-'A']=true;
	cout << dfs(1,1);

	return 0;
}

int dfs(int i, int j)
{
	// right, bottom, left, top
	const int dx[] = {1,0,-1,0};
	const int dy[] = {0,-1,0,1};
	int movement = 1;

	for (int d = 0; d<4; ++d) {
		int x = i+dx[d];
		int y = j+dy[d];

		if (x<1 || x>r) {
			continue;
		}
		if (y<1 || y>c) {
			continue;
		}
		if (is_visited[arr[x][y]-'A']) {
			continue;
		}
		is_visited[arr[x][y]-'A']=true;
		movement = max(movement,dfs(x,y)+1);
		is_visited[arr[x][y]-'A']=false;
	}
	
	return movement;
}