#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<int> arr(101);
    for (int i = 1; i<=n; ++i) {
        int x, y;
        cin>>x>>y;
        arr[x]=y;
    }
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        arr[u]=v; 
    }

    vector<int> dist(101);
    fill(dist.begin(),dist.end(),-1);
    queue<int> q;
    q.push(1);
    dist[1]=0; 
    while (!q.empty()) {
        const vector<int> move = {1,2,3,4,5,6};

        auto cur = q.front();
        q.pop();
        if (cur==100) {
            break;
        }
        for (auto m : move) {
            int x = cur+m;
            
            if (x>100) {
                continue;
            }
            if (dist[x]!=-1) {
                continue;
            }
            dist[x]=dist[cur]+1;
            if (arr[x]) {
                if (dist[arr[x]]==-1 || dist[arr[x]]>dist[x]) {
                    q.push(arr[x]);
                    dist[arr[x]]=dist[x];
                }
            }
            else {
                q.push(x);
            }
        }
    }
    cout << dist[100];

    return 0;
}