// http://icpc.me/15683
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

bool is_within(int, int);
void update(int, int, int);

// { x, y }
int area[10][10]; // 0, 1 ~ 8, escape OOB
int temp[10][10]; // 1: true, 0: false

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m; // n(x), m(y)
    int min_blind_spot = 0;
    vector<pair<int, int>> cam;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            cin>>area[i][j]; // { x, y }
            if (area[i][j]==0) {
                ++min_blind_spot;
            } else if (area[i][j]>=1 && area[i][j]<=5) {
                cam.push_back({i,j});
            }
        }
    }
    // 0 ~ 4^k - 1
    for (int n_case = 0; n_case<(1<<(cam.size()*2)); ++n_case) {
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<m; ++j) {
                temp[i][j]=area[i][j];
            }
        }
        int dir_info = n_case;

        for (int i = 0; i<cam.size(); ++i) {
            int x = cam[i].X;
            int y = cam[i].Y;
            int dir = dir_info % 4;
            switch (area[x][y]) {
            case 1: 
                update(x,y,dir);
                break;
            case 2: 
                update(x,y,dir);
                update(x,y,dir+2);
                break;
            case 3:
                update(x,y,dir);
                update(x,y,dir+1);
                break;
            case 4:
                update(x,y,dir);
                update(x,y,dir+1);
                update(x,y,dir+2);
                break;
            case 5:
                update(x,y,dir);
                update(x,y,dir+1);
                update(x,y,dir+2);
                update(x,y,dir+3);
                break;
            default:
                break;
            }
            dir_info/=4;
        }

        int blind_spot = 0;
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<m; ++j) {
                if (!temp[i][j]) {
                    ++blind_spot;
                }
            }
        }
        min_blind_spot = min(min_blind_spot,blind_spot);
    }
    cout << min_blind_spot;

    return 0;
}

bool is_within(int x, int y) 
{

    return (x>=0 && x<n) && (y>=0 && y<m);
}

void update(int x,int y,int dir)
{
    dir%=4;
    while (1) {
        x+=dx[dir];
        y+=dy[dir];
        if (!is_within(x,y) || temp[x][y] == 6) {

            return;
        }
        if (temp[x][y]==0) {
            temp[x][y]=7; // patrol
        }
    }

    return;
}