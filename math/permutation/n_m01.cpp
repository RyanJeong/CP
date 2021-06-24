// http://icpc.me/15649
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nPm
    int n, m;
    cin>>n>>m;
    int arr[8];
    for (int i = 0; i<n; ++i) {
        arr[i]=i+1;
    }
    do {
        for (int i = 0; i<m; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        // 1 2 3 4 5 -> 1 2 5 4 3, 1 3 2 4 5 -> 1 3 5 4 2, ...
        reverse(arr+m, arr+n);
    } while (next_permutation(arr,arr+n));

    return 0;
}