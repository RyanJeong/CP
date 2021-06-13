// http://icpc.me/15686
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int arr[52][52]; // 0, 1, 2 ~ 50, OOB
int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int ,int>> store, house;
    cin>>n>>m;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            cin>>arr[i][j];
            if (arr[i][j]==2) {
                store.push_back({i,j});
            } else if (arr[i][j]==1) {
                house.push_back({i,j});
            }
        }
    }

    // nCr
    vector<int> is_used(store.size(),1);
    fill(is_used.begin(),is_used.begin()+store.size()-m,0);
    int opt_dist = 2e9;

    do {
        int dist = 0;

        for (auto h : house) {
            int dist_per_house = 2e9;

            for (int i = 0; i<store.size(); ++i) {
                if (is_used[i]) {
                    dist_per_house=min(dist_per_house,abs(store[i].X-h.X)+abs(store[i].Y-h.Y));
                }
            }
            dist+=dist_per_house;
        }
        opt_dist=min(opt_dist,dist);
    } while (next_permutation(is_used.begin(),is_used.end()));
    cout << opt_dist;

    return 0;
}
