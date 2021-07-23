// https://www.acmicpc.net/problem/13700
// 완전 범죄
// 1차원에서의 BFS
// step 별 bfs 탐색
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static bool is_visited[100'001];
    int n, s, d, f, b, k;
    cin>>n>>s>>d>>f>>b>>k;
    for (int i = 1; i<=k; ++i) {
        int l;
        cin>>l;
        is_visited[l]=true;
    }

    vector<int> dx;
    dx.push_back(f);
    dx.push_back(-b);
    queue<int> q;
    q.push(s);
    is_visited[s]=true;
    int time = 0;
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            auto cur = q.front();
            q.pop();
            if (cur==d) {
                cout << time;

                return 0;
            }
            for (int i = 0; i<2; ++i) {
                int x = cur+dx[i];
                if (x<1 || x>n) {
                    continue;
                }
                if (is_visited[x]) {
                    continue;
                }
                q.push(x);
                is_visited[x]=true;
            }
        }
        ++time;
    }
    cout << "BUG FOUND";

    return 0;
}