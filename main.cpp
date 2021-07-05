// https://www.acmicpc.net/problem/3830
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int, int);

vector<int> parent;
vector<long long> diff;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, m;
        cin>>n>>m;
        if (!n && !m) {
            break;
        }
        parent=vector<int>(n+1);
        for (int i = 1; i<=n; ++i) {
            parent[i]=i;
        }
        for (int i = 1; i<=m; ++i) {

        }
    }

    return 0;
}

int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }
    int p_u = find(parent[u]);
    diff[u]+=diff[parent[u]];

    return parent[u]=p_u
}

void merge(int u, int v, int w)
{
    if (find(u)==find(v)) {
        
        return; 
    }
    parent[find(v)]=find(u);

    return;
}