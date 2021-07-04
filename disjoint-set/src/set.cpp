// https://www.acmicpc.net/problem/1717
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i = 0; i<=n; ++i) {
        parent.push_back(i);
        level.push_back(1);
    }
    for (int i = 0; i<m; ++i) {
        int c;
        cin>>c;
        int u;
        cin>>u;
        int v;
        cin>>v;
        if (!c) { // union
            merge(u,v);
        }
        else { // find
            cout << ((find(u)==find(v)) ? "YES" : "NO") << '\n';
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
