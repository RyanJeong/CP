// https://www.acmicpc.net/problem/1922
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    parent=vector<int>(v+1);
    level=vector<int>(v+1,1);
    for (int i = 0; i<=v; ++i) {
        parent[i]=i;
    }
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i<e; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        if (a==b) {
            continue;
        }
        edge.push_back({c,make_pair(a,b)});
    }
    sort(edge.begin(),edge.end());
    e=edge.size();

    int cnt = 0;
    int res = 0;
    for (int i = 0; i<e; ++i) {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;

        if (find(v1)==find(v2)) {
            continue;
        }
        merge(v1,v2);
        res+=cost;
        ++cnt;
        if (cnt==v-1) {
            break;
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