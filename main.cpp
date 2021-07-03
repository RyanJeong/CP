// https://www.acmicpc.net/problem/3190
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[101][101];
    int n;
    cin>>n;
    int k;
    cin>>k;
    for (int i = 1; i<=k; ++i) {
        int x;
        cin>>x;
        int y;
        cin>>y;
        arr[x][y]=-1;
    }
    int l;
    queue<pair<int, char>> q;
    for (int i = 1; i<=l; ++i) {
        int time;
        cin>>time;
        char dir;
        cin>>dir;
        q.push({time,dir});
    }

    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,-1,0,1};
    int dir = 1;




    return 0;
}