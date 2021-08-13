// https://www.acmicpc.net/problem/4386
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin>>v;
    parent=vector<int>(v+1);
    level=vector<int>(v+1,1);
    for (int i = 0; i<=v; ++i) {
        parent[i]=i;
    }
    vector<pair<double, double>> freckle(v+1);
    for (int i = 1; i<=v; ++i) {
        cin>>freckle[i].first>>freckle[i].second;
    }
    vector<pair<double, pair<int, int>>> edge;
    for (int i = 1; i<v; ++i) {
        for (int j = i+1; j<=v; ++j) {
            auto p1 = freckle[i];
            auto p2 = freckle[j];
            double dist_x = p1.first-p2.first;
            double dist_y = p1.second-p2.second;
            double cost = sqrt(dist_x*dist_x+dist_y*dist_y);
            edge.push_back({cost,make_pair(i,j)});
        }
    }
    sort(edge.begin(),edge.end());
    int e = edge.size();

    int cnt = 0;
    double res = 0.0;
    for (int i = 0; i<e; ++i) {
        double cost = edge[i].first;
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
    cout << fixed;
    cout.precision(2);
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
