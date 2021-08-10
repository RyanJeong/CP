// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> is_visited;

void dfs(int);
void bfs(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, v;
    cin>>n>>m>>v;
    vector<pair<int, int>> tmp(m+1);
    for (int i = 1; i<=m; ++i) {
        cin>>tmp[i].first>>tmp[i].second;
    }
    sort(tmp.begin()+1,tmp.end(),greater<>());

    adj_list=vector<vector<int>>(n+1);
    for (int i = 1; i<=m; ++i) {
        adj_list[tmp[i].first].push_back(tmp[i].second);
        adj_list[tmp[i].second].push_back(tmp[i].first);
    }
    is_visited=vector<bool>(1001);
    dfs(v);
    is_visited=vector<bool>(1001);
    bfs(v);

    return 0;
}

void dfs(int v)
{
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (is_visited[cur]) {
            continue;
        }
        is_visited[cur]=true;
        cout << cur << ' ';

        for (int next : adj_list[cur]) {
            if (is_visited[next]) {
                continue;
            }
            s.push(next);
        }
    }
    cout << '\n';

    return;
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    is_visited[v]=true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : adj_list[cur]) {
            if (is_visited[next]) {
                continue;
            }
            q.push(next);
            is_visited[next]=true;
        }
    }
    cout << '\n';

    return;
}