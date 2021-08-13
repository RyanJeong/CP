// https://www.acmicpc.net/problem/17472
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
    vector<vector<bool>> is_land(n+1,vector<bool>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            int tmp;
            cin>>tmp;
            is_land[i][j]=((tmp) ? true : false);
        }
    }
    
    int v = 0;
    vector<vector<int>> arr(n+1,vector<int>(m+1));
    vector<vector<pair<int, int>>> island(1);
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (!is_land[i][j] || arr[i][j]) {
                continue;
            }

            queue<pair<int, int>> q;
            q.push({i,j});
            arr[i][j]=++v;
            vector<pair<int, int>> tmp;
            tmp.push_back({i,j});
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                const vector<pair<int, int>> adjacency = {
                    {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                };
                for (auto d : adjacency) {
                    int x = cur.first+d.first;
                    int y = cur.second+d.second;

                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (!is_land[x][y] || arr[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    arr[x][y]=v;
                    tmp.push_back({x,y});
                }
            }
            sort(tmp.begin(),tmp.end());
            island.push_back(tmp);
        }
    }

    // get edges
    // cost, u, v
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 1; i<=v; ++i) {
        for (auto cur : island[i]) {
            const vector<pair<int, int>> adjacency = {
                {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
            };
            for (auto d : adjacency) {
                int gap = 0;
                int x = cur.first;
                int y = cur.second;
                while (1) {
                    x+=d.first;
                    y+=d.second;
                    if (x<1 || x>n) {
                        break;
                    }
                    if (y<1 || y>m) {
                        break;
                    }
                    if (arr[x][y]==i) {
                        break;
                    } 
                    if (!is_land[x][y]) { // sea
                        ++gap;
                        continue;
                    }
                    if (arr[x][y]!=i) {
                        if (gap>1) {
                            edge.push_back({gap,make_pair(i,arr[x][y])});
                        }
                        break;
                    }
                }
            }
        }
    }
    sort(edge.begin(),edge.end());
    int e = edge.size();

    parent=vector<int>(v+1);
    level=vector<int>(v+1,1);
    for (int i = 0; i<=v; ++i) {
        parent[i]=i;
    }
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

    for (int i = 1; i<v; ++i) {
        if (find(i)!=find(i+1)) {
            cout << -1;
            
            return 0;
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