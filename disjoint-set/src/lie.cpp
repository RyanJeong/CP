// https://www.acmicpc.net/problem/1043
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
    int t;
    cin>>t;
    vector<int> v(t);
    for (int i = 0; i<t; ++i) {
        cin>>v[i];
    }
    vector<vector<int>> party(m);
    for (int i = 0; i<m; ++i) {
        int size;
        cin>>size;
        party[i]=vector<int>(size);
        for (int j = 0; j<size; ++j) {
            cin>>party[i][j];
        }
    }

    for (int i = 0; i<=n; ++i) {
        parent.push_back(i);
        level.push_back(1);
    }
    for (int e : v) {
        merge(e,v.front());
    }
    for (int i = 0; i<m; ++i) {
        for (int e : party[i]) {
            merge(e,party[i].front());
        }
    }

    int res = 0;
    for (int i = 0; i<m; ++i) {
        if (v.empty() || find(v.front())!=find(party[i].front())) {
            ++res;
        }
    }
    cout << res;

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
