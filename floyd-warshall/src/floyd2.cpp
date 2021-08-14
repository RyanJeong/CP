// https://www.acmicpc.net/problem/11780
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> d(n+1,vector<int>(n+1));
    vector<vector<int>> p(n+1,vector<int>(n+1));
    fill(d.begin(),d.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        d[i][i]=0;
    }
    while (m--) {
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
        p[a][b]=a;
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                if (d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (d[i][j]==1e9) {
                cout << 0;
            }
            else {
                cout << d[i][j];
            }
            cout << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (!p[i][j]) {
                cout << 0;
            }
            else {
                stack<int> s;
                int r = j;
                s.push(r);
                while (p[i][r]!=i) {
                    r=p[i][r];
                    s.push(r);
                }
                s.push(i);
                cout << s.size() << ' ';
                while (!s.empty()) {
                    cout << s.top() << ' ';
                    s.pop();
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
