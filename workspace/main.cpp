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
    vector<int> v(t+1);
    for (int i = 1; i<=t; ++i) {
        cin>>v[i];
    }
    vector<vector<int>> party(m+1);
    for (int i = 1; i<=m; ++i) {
        int size;
        cin>>size;
        while (size--) {
            int tmp;
            cin>>tmp;
            party[i].push_back(tmp);
        }
    }

    if (!t) {
        cout << m;

        return 0;
    }
    for (int i = 0; i<=n; ++i) {
        parent.push_back(i);
        level.push_back(1);
    }
    for (int i = 2; i<=t; ++i) {
        merge(v[1],v[i]);
    }
    int group = v[1];

    for (int i = 1; i<=m; ++i) {
        bool is_found = false;
        for (int e : party[i]) {
            if (find(e)==find(group)) {
                is_found=true;
                break; 
            }
        }
        if (!is_found) {
            continue;
        }
        for (int e : party[i]) {
            merge(group,e);
        }
    }

    int cnt = 0;
    for (int i = 1; i<=m; ++i) {
        bool is_found = false;
        for (int e : party[i]) {
            if (find(e)==find(group)) {
                is_found=true;
                break; 
            }
        }
        if (!is_found) {
            ++cnt;
        }
    }
    cout << cnt;

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
