// http://icpc.me/15655
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nCm
    int n, m;
    cin>>n>>m;
    vector<int> v;

    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    vector<bool> is_used;

    // 1 1 ... 0 0
    // prev_permutation => 0 0 ... 1 1 
    for (int i = 0; i<m; ++i) {
        is_used.push_back(1);
    }
    for (int i = m; i<n; ++i) {
        is_used.push_back(0);
    }
    do {
        for (int i = 0; i<n; ++i) {
            if (is_used[i]) {
                cout << v[i] << ' ';
            }
        }
        cout << '\n';
    } while (prev_permutation(is_used.begin(),is_used.end()));

    return 0;
}
