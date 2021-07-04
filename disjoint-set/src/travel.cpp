// https://www.acmicpc.net/problem/1976
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

    parent = vector<int>(n+1);
    level = vector<int>(n+1,1);
    for (int i = 1; i<=n; ++i) {
        parent[i]=i;
    }
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            int temp;
            cin>>temp;
            if (temp) {
                merge(i,j);
            }
        }
    }

    vector<int> path(m+1);
    for (int i = 1; i<=m; ++i) {
        cin>>path[i];
    }
    bool is_linked=true;
    for (int i = 1; i<m; ++i) {
        if (find(path[i])!=find(path[i+1])) {
           is_linked=false;
           break;
        }
    }
    cout << ((is_linked) ? "YES" : "NO") << '\n';

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
