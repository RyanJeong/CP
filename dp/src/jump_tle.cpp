#include <bits/stdc++.h>

using namespace std;

void bt(int, int);

int arr[101][101];
bool is_visited[101][101];
int n, cnt;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
        }
    }
    bt(1,1);
    cout << cnt;

    return 0;
}

void bt(int i, int j)
{
    if (i==n && j==n) {
        ++cnt;

        return;
    }
    if (i<1 || j>n) {

        return;
    }
    if (i<1 || j>n) {

        return;
    }
    if (is_visited[i][j]) {

        return;
    }
    is_visited[i][j]=true;
    int d = arr[i][j];
    bt(i+d,j);
    bt(i,j+d);
    is_visited[i][j]=false;

    return;
}