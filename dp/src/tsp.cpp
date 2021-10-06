#include <bits/stdc++.h>

using namespace std;

// Traveling Salesman Problem
int tsp(int cur, int b_visited);

int g_n;
vector<vector<int>> g_cost;
vector<vector<int>> g_v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>g_n;
    g_v=vector<vector<int>>(g_n,vector<int>(1<<g_n));
    fill(g_v.begin(),g_v.end(),vector<int>(1<<g_n,-1));
    g_cost=vector<vector<int>>(g_n,vector<int>(g_n));
    for (int i = 0; i<g_n; ++i) {
        for (int j = 0; j<g_n; ++j) {
            cin>>g_cost[i][j];
        }
    }
    // 0 ~ n-1 도시 중 어느 도시를 시작점으로 설정해도 결과는 같음:
    // 0->1->2->3->0
    // 1->2->3->0->1
    // ...
    cout << tsp(0,1<<0);

    return 0;
}

// 시간복잡도는 O(n^2*2^n)
// 모든 도시를 순회하는 경우의 수는 n*2
// b_visited의 경우의 수는 2^n
int tsp(int cur, int b_visited)
{
    // 모든 도시 방문을 마친 상태:
    if (b_visited==(1<<g_n)-1) {

        return ((g_cost[cur][0]) ? g_cost[cur][0] : 1e9);
    }

    // 이전에 방문한 적 있는 도시인 경우:
    if (g_v[cur][b_visited]!=-1) {

        return g_v[cur][b_visited];
    }

    g_v[cur][b_visited]=1e9;
    for (int next = 0; next<g_n; ++next) {
        // 현재 도시에서 다음 도시로 갈 수 있는 상태가 아닌 경우:
        if (g_cost[cur][next]==0) {
            continue;
        }

        // 이전에 방문한 적 있는 도시인 경우:
        if (b_visited&(1<<next)) {
            continue;
        }

        // 현재 도시에서 다른 도시들을 순회할 때 발생하는 최소비용 계산:
        g_v[cur][b_visited]=min(g_v[cur][b_visited],g_cost[cur][next]+tsp(next,b_visited|1<<next));
    }

    return g_v[cur][b_visited];
}
