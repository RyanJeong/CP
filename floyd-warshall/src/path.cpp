// https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> d(n+1,vector<int>(n+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>d[i][j];
        }
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                if (d[i][k] && d[k][j]) {
                    d[i][j]=1;
                }
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (d[i][j]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
