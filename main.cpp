// http://icpc.me/2565
#include <bits/stdc++.h>

using namespace std;

int arr[501][2]; // [0] -> to, [1] -> tangled
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        int a, b;
        cin>>a>>b;
        arr[a][0]=b;
    }

    // 1. get number of tangled line per position
    for (int i = 1; i<=n; ++i) {
        if (!arr[i][0]) {
            continue;
        }
        int to = arr[i][0];
        for (int j = i+1; j < to; ++j) {
            ++arr[j][1];
        }
    }
    for (int i = 1; i<=n; ++i) {
        cout << arr[i][1] << '\n';
    }
    /*
    int max_tangled_line = -1;
    int min_line = 0;
    while (!max_tangled_line) {
        for (int i = 1; i<=n; ++i) {
        }
    }
    cout << min_line;
    */

    return 0;
}