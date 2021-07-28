// https://www.acmicpc.net/problem/12100
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> arr(n+1,vector<int>(n+1)); // 1-based
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
        }
    }

    int res = 0;
    const int limit = 4*4*4*4*4; // {up down left right} x 5 times
    for (int c = 0; c<limit; ++c) {
        int dir = c;
        vector<vector<int>> tmp(arr);
        const int trial = 5;
        for (int t = 0; t<trial; ++t) {
            int d = dir%4;

            // 1. rotate
            while (d--) {
                vector<vector<int>> buf(tmp);

                for (int i = 1; i<=n; ++i) {
                    for (int j = 1; j<=n; ++j) {
                        tmp[i][j] = buf[n-j+1][i]; // 1-based
                    }
                }
            }            

            // 2. move to left
            for (int i = 1; i<=n; ++i) {
                vector<int> ith_row(n+1,0);
                int idx = 1;
                for (int j = 1; j<=n; ++j) {
                    if (!tmp[i][j]) {
                        continue;
                    }
                    if (!ith_row[idx]) {
                        ith_row[idx]=tmp[i][j];
                    } 
                    else if (ith_row[idx]==tmp[i][j]) {
                        ith_row[idx++]*=2;
                    } 
                    else {
                        ith_row[++idx]=tmp[i][j];
                    }
                }
                tmp[i]=ith_row;
            }
            dir/=4;
        }
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                res=max(tmp[i][j],res);
            }
        }
    }
    cout << res;

    return 0;
}