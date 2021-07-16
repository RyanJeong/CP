// https://www.acmicpc.net/problem/2571
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int a[101][101];
    static int s[101][101];
    int n;
    cin>>n;
    while (n--) {
        int x1, y1;
        cin>>x1>>y1;
        int x2 = min(x1+10,100);
        int y2 = min(y1+10,100);
        for (int i = x1; i<x2; ++i) {
            for (int j = y1; j<y2; ++j) {
                a[i][j]=1;
            }
        }
    }

    for (int i = 1; i<=100; ++i) {
        for (int j = 1; j<=100; ++j) {
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    int res = 0;
    for (int i = 1; i<=100; ++i) {
        for (int j = 1; j<=100; ++j) {
            for (int r = 1; r<=i; ++r) {
                for (int c = 1; c<=j; ++c) {
                    int tmp = s[i][j]-s[i][c-1]-s[r-1][j]+s[r-1][c-1];
                    // check
                    if (tmp==(i-r+1)*(j-c+1)) {
                        res=max(res,tmp);
                    }
                }
            }
        }
    }
    cout << res;

    return 0;
}
