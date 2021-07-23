// https://www.acmicpc.net/problem/2630
#include <bits/stdc++.h>

using namespace std;

void rec(int, int, int);

int arr[128+1][128+1]; // 1-based
int n_white;
int n_blue;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
        }
    }
    rec(n,1,1);
    cout << n_white << '\n' << n_blue;

    return 0;
}

void rec(int n, int x, int y)
{
    if (n==1) {
        (arr[x][y]) ? ++n_blue : ++n_white;

        return;
    }
    bool is_white = true;
    bool is_blue = true;
    for (int i = x; i<x+n; ++i) {
        for (int j = y; j<y+n; ++j) {
            if (arr[i][j]) {
                
            }
        }
    }
    for (int i = x; i<x+n; ++i) {
        for (int j = y; j<y+n; ++j) {
            if (arr[i][j]) {
                is_white=false;
            } 
            else {
                is_blue=false;
            }
        }
    }
    if (is_white) {
        ++n_white;
    }
    if (is_blue) {
        ++n_blue;
    }
    else {
        n/=2;
        rec(n,x,y);
        rec(n,x,y+n);
        rec(n,x+n,y);
        rec(n,x+n,y+n);
    }

    return;
}