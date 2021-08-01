// https://www.acmicpc.net/problem/1958
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y, z;
    cin>>x>>y>>z;
    int x_len = x.size();
    int y_len = y.size();
    int z_len = z.size();
    x.insert(x.begin(), '\0'); // 1-based
    y.insert(y.begin(), '\0'); // 1-based
    z.insert(z.begin(), '\0'); // 1-based
    static int c[101][101][101]; // init. all to zero
    for (int i = 1; i<=x_len; ++i) {
        for (int j = 1; j<=y_len; ++j) {
            for (int k = 1; k<=z_len; ++k) {
                if (x[i]==y[j] && y[j]==z[k]) {
                    c[i][j][k]=c[i-1][j-1][k-1]+1;
                }
                else {
                    c[i][j][k]=max({c[i-1][j][k],c[i][j-1][k],c[i][j][k-1]});
                }
            }
        }
    }
    cout << c[x_len][y_len][z_len];

    return 0;
}