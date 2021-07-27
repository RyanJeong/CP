// https://www.acmicpc.net/problem/15683
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m; 
    int arr[n+1][m+1];
    int tmp[n+1][m+1];
    vector<pair<int, int>> cam(1); // 1-based
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>arr[i][j];
            if (arr[i][j]>=1 && arr[i][j]<=5) {
                cam.push_back({i,j});
            }
        }
    }

    int min_area = 64;
    // cam: 4 directions
    // ex) n(cam): 3 -> 4x4x4
    int cases = 1<<(cam.size()*2);
    for (int c = 0; c<cases; ++c) {
        memcpy(tmp,arr,sizeof tmp);
        int dir = c;
        for (int i = 1; i<=cam.size(); ++i) {
            const int dx[] = {1,0,-1,0};
            const int dy[] = {0,1,0,-1}; 
            bool is_available[4] = {false,false,false,false};
            switch (arr[cam[i].first][cam[i].second]) {
            case 1: 
                is_available[(dir+0)%4]=true;
                break;
            case 2: 
                is_available[(dir+0)%4]=true;
                is_available[(dir+2)%4]=true;
                break;
            case 3: 
                is_available[(dir+0)%4]=true;
                is_available[(dir+1)%4]=true;
                break;
            case 4: 
                is_available[(dir+0)%4]=true;
                is_available[(dir+1)%4]=true;
                is_available[(dir+2)%4]=true;
                break;
            case 5: 
                is_available[(dir+0)%4]=true;
                is_available[(dir+1)%4]=true;
                is_available[(dir+2)%4]=true;
                is_available[(dir+3)%4]=true;
                break;
            default:
                break;
            }
            for (int d = 0; d<4; ++d) {
                if (!is_available[d]) {
                    continue;
                }
                int x = cam[i].first;
                int y = cam[i].second;
                while (tmp[x][y]!=6) {
                    x+=dx[d];
                    y+=dy[d];
                    if (x<1 || x>n) {
                        break;
                    }
                    if (y<1 || y>m) {
                        break;
                    }
                    if (tmp[x][y]==0) {
                        tmp[x][y]=9; // p
                    }
                }
            }
            dir/=4;
        }
        int area = 0;
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=m; ++j) {
                if (!tmp[i][j]) {
                    ++area;
                }
            }
        }
        min_area=min(min_area,area);
    }
    cout << min_area;

    return 0;
}