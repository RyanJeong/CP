// https://www.acmicpc.net/problem/1707
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            cin>>v[i][j];
        }
    }

    vector<int> is_used(n);
    fill(is_used.begin()+n/2,is_used.end(),1);
    int res = 190*100;
    do {
        vector<int> v1, v2;
        for (int i = 0; i<n; ++i) {
            if (is_used[i]) {
                v1.push_back(i);
            }
            else {
                v2.push_back(i);
            }
        }

        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i<n/2; ++i) {
            for (int j = i+1; j<n/2; ++j) {
                t1+=v[v1[i]][v1[j]]+v[v1[j]][v1[i]];
                t2+=v[v2[i]][v2[j]]+v[v2[j]][v2[i]];
            }
        }

        res=min(res,abs(t1-t2));
    } while (next_permutation(is_used.begin(),is_used.end()));
    cout << res;
    
    return 0;
}