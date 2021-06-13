// http://icpc.me/15654
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nPm
    int n, m;
    cin>>n>>m;
    vector<int> v;

    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    do {
        for (int i = 0; i<m; ++i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        // 1 2 3 4 5 -> 1 2 5 4 3, 1 3 2 4 5 -> 1 3 5 4 2, ...
        reverse(v.begin()+m,v.end());
    } while (next_permutation(v.begin(),v.end()));

    return 0;
}