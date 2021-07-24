// https://www.acmicpc.net/problem/16562
// 친구비
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;
vector<int> cost;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;
    parent=vector<int>(n+1,0); // 1-based
    cost=vector<int>(n+1,0);
    for (int i = 1; i<=n; ++i) {
        parent[i]=i;
        cin>>cost[i];
    }
    level=vector<int>(n+1,1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        merge(u,v);
    }
    set<int> s;
    for (int i = 1; i<=n; ++i) {
        s.insert(find(i));
    }
    int total_cost = 0;
    for (int i : s) {
        total_cost+=cost[i];
    }
    if (total_cost>k) {
        cout << "Oh no";
    }
    else {
        cout << total_cost;
    }

    return 0;
}

int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }

    return parent[u]=find(parent[u]);
}

void merge(int u, int v)
{
    u=find(u); 
    v=find(v); 
    if (u==v) {
        
        return; 
    }
    if (level[u]>level[v]) {
        swap(u,v); 
    }
    parent[u]=v;
    cost[v]=min(cost[u],cost[v]);
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return;
}
