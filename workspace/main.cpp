// https://www.acmicpc.net/problem/1197
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    vector<pair<int, pair<int, int>>> edge(e);
    for (int i = 0; i<e; ++i) {
        cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
    }

    sort(edge.begin(),edge.end());
    priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
    

    return 0;
}