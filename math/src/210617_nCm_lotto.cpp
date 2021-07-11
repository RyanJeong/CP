//http://icpc.me/6603
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int k;
        cin>>k;

        if (!k) {
            break;
        }
        int n = k;
        int m = 6;
        vector<int> v, comb;
        while (k--) {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }

        // nCm
        // 0: select, 1: skip
        for (int i = 0; i<m; ++i) {
            comb.push_back(0);
        }
        for (int i = m; i<n; ++i) {
            comb.push_back(1);
        }
        do {
            // next_permutation, 0 0 1 1 => 1 1 0 0
            // prev_permutation, 1 1 0 0 => 0 0 1 1
            for (int i = 0; i<n; ++i) {
                if (comb[i]==0) {
                    cout << v[i] << ' ';
                }
            }
            cout << '\n';
        } while (next_permutation(comb.begin(),comb.end()));
        cout << '\n';
    }

    return 0;
}