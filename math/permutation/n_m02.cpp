// http://icpc.me/15650
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nCm
    int n, m;
    cin>>n>>m;
    int arr[8];
    for (int i = 0; i<n; ++i) {
        arr[i]=i+1;
    }
    vector<int> v;

    // next_permutation, 0 0 1 1 => 1 1 0 0
    // prev_permutation, 1 1 0 0 => 0 0 1 1
    for (int i = 0; i<m; ++i) {
        v.push_back(0);
    }
    for (int i = m; i<n; ++i) {
        v.push_back(1);
    }
    do {
        for (int i = 0; i<n; ++i) {
            if (!v[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    } while (next_permutation(v.begin(),v.end()));

    return 0;
}
