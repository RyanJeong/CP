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
    int n, m;
    cin>>n>>m;
    parent=vector<int>(n+1);
    level=vector<int>(n+1,1);
    for (int i = 0; i<=n; ++i) {
        parent[i]=i;
    }
    for (int i = 0; i<m; ++i) {
        int c, u, v;
        cin>>c>>u>>v;

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
