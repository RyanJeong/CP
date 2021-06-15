//http://icpc.me/6593
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	const int dx[] = {1,0,-1,0,0,0};
	const int dy[] = {0,1,0,-1,0,0}; 
	const int dz[] = {0,0,0,0,1,-1}; 

	while (1) {
		int l, r, c;
		cin>>l>>r>>c;
		if (!l && !r && !c) {
			break;
		}
		// Init.
		int arr[31][31][31]; // 0, 1 ~ 30
		bool is_visited[31][31][31];
		memset(is_visited, 0, sizeof is_visited);

		// dimension, x, y
		queue<pair<int, pair<int, int>>> q;
		for (int i = 1; i<=l; ++i) {
			for (int j = 1; j<=r; ++j) {
				string str;
				cin>>str;
				int k = 1;

				for (char c : str) {
					switch (c) {
					// 'S' '.' -> 0, '#' -> -1, 'E' -> 1
					case 'S':
						arr[i][j][k]=0;
						q.push({i,make_pair(j,k)});
						is_visited[j][k];
						break;
					case '.':
						arr[i][j][k]=0;
						break;
					case '#':
						arr[i][j][k]=-1;
						break;
					case 'E':
						arr[i][j][k]=1;
						break;
					default:
						break;
					}
					++k;
				}
			}
		}
		// is_escaped
		// while (!q.empty()
		// int minute
	}

	return 0;
}