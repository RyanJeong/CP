//http://icpc.me/1261
#include <bits/stdc++.h>

using namespace std;

void dfs(int, int, int);

int n, m;
vector<int> answer;
bool arr[101][101];
bool is_visited[101][101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    for (int i = 1; i<=n; ++i) {
        string s;
        cin>>s;

        int j = 1;
        for (char c : s) {
            arr[i][j++]=c-'0';
        }
    }

    is_visited[1][1]=1;
    dfs(1,1,arr[1][1]);
    sort(answer.begin(),answer.end());
    cout << answer.front();

    return 0;
}

void dfs(int i, int j, int cnt)
{
	// right, botq_tom, left, top
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,-1,0,1};

    if (i==n && j==m) {
        answer.push_back(cnt);

        return;
    }
    for (int d = 0; d<4; ++d) {
        int x = i+dx[d];
        int y = j+dy[d];

        if (x<1 || x>n) {
            continue;
        }
        if (y<1 || y>m) {
            continue;
        }
        if (is_visited[x][y]) {
            continue;
        }
        is_visited[x][y]=true;
        dfs(x,y,cnt+arr[x][y]);
        is_visited[x][y]=false;
    }

    return;
}