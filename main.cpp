// https://www.acmicpc.net/problem/16920
// 1. 1~n 순서대로 bfs
// 2. bfs 카운트 배열에 기록
// 3. 기록하면서 개수 카운트
// 4. 1에 대해서 수행이 완료되면 2에 대해서 2~3 반복 
// 4-1. 1이 기록한 배열에 2가 덮어쓰되, 1이 기록한 숫자 중 작은 수만 2가 새로 덮어씀
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[1001][1001];
    static bool is_visited[1001][1001];
    static int movement[10];
    int n, m, p;
    cin>>n>>m>>p;
    for (int i = 1; i<=p; ++i) {
        cin>>movement[i];
    }
    vector<pair<int, int>> v[p+1];
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            char c;
            cin>>c;
            if (isdigit(c)) {
                v[c-'0'].push_back({i,j});
            }
        }
        cin.ignore();
    }

    // bfs
    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,-1,0,1};
    //for (int i = 1; i<=p; ++i) while (!v[i].empty())

    return 0;
}