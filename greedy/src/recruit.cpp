// https://www.acmicpc.net/problem/1946
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;

        vector<int> v(n+1);
        for (int i = 0; i<n; ++i) {
            int a, b;
            cin>>a>>b;
            v[a]=b;
        }

        int mark = n;
        int res = 0;
        for (int i = 1; i<=n; ++i) {
            if (mark<v[i]) {
                continue;
            }
            mark=v[i];
            ++res;
        }
        cout << res << '\n';
    }

    return 0;
}