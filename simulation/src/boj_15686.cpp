// https://www.acmicpc.net/problem/15686
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1, vector<int>(n+1)); // 1-based;
    vector<pair<int ,int>> store, house;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
            if (arr[i][j]==1) {
                house.push_back({i,j});
            }
            if (arr[i][j]==2) {
                store.push_back({i,j});
            }
        }
    }

    // combinations
    vector<int> v;
    for (int i = 0; i<m; ++i) {
        v.push_back(0);
    }
    for (int i = m; i<store.size(); ++i) {
        v.push_back(1);
    }
    int min_dist = 2e9;
    do {
        int dist = 0;
        for (auto h : house) {
            int dist_per_house = 2e9;
            for (int i = 0; i<store.size(); ++i) {
                if (!v[i]) {
                    dist_per_house=min(dist_per_house,abs(store[i].first-h.first)+abs(store[i].second-h.second));
                }
            }
            dist+=dist_per_house;
        }
        min_dist=min(min_dist,dist);
    } while (next_permutation(v.begin(),v.end()));
    cout << min_dist;

    return 0;
}