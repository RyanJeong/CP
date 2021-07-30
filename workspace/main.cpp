// https://www.acmicpc.net/problem/1939
// 중량제한
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    parent=vector<int>(n+1,0);
    for (int i = 1; i<=n; ++i) {
        parent[i]=i;
    }
    level=vector<int>(n+1,1);
    vector<pair<int, pair<int, int>>> info(1);
    for (int i = 1; i<=m; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        info.push_back({w,make_pair(u,v)});
    }
    int a, b;
    cin>>a>>b;

    // 서로 다른 두 중량이 주어졌을 때
    // 주어진 상황에서 적용되는 중량은 두 중량 중 낮은 중량임
    // 따라서 중량제한이 높은 경우부터 차례대로 조사

    // 문제에서 요구하는 섬이 연결되었을 때의 중량이
    // 우리가 구하고자 하는 중량값임 
    sort(info.begin(),info.end(),greater<>());
    for (int i = 1; i<=m; ++i) {
        int u = info[i].second.first;
        int v = info[i].second.second;
        int w = info[i].first;
        merge(u,v);
        if (find(a)==find(b)) {
            cout << w;
            break;
        }
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
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return;
}