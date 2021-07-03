//http://icpc.me/7562
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // { x, y }
    int arr[300][300]; // count of movement
    // knight's movement
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    // case
    int t;
    cin>>t;

    while (t--) {
        memset(arr, 0, sizeof arr);
        int l;
        cin>>l;
        int x1,y1;
        cin>>x1>>y1;
        int x2,y2;
        cin>>x2>>y2;
        queue<pair<int, int>> q;
        q.push({x1,y1});

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            if (cur.first==x2 && cur.second==y2) {
                break;
            }
            for (int d = 0; d <8; ++d) {
                int x = cur.first+dx[d];
                int y = cur.second+dy[d];

                if (x<0 || x>=l) {
                    continue;
                }
                if (y<0 || y>=l) {
                    continue;
                }
                if (arr[x][y]>arr[cur.first][cur.second]+1 || !arr[x][y]) {
                    arr[x][y]=arr[cur.first][cur.second]+1;
                    q.push({x,y});
                }
            }
        }
        cout << arr[x2][y2] << '\n';
    }

    return 0;
}