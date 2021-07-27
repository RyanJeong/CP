// https://www.acmicpc.net/problem/18808
#include <bits/stdc++.h>

using namespace std;

bool is_suitable(int, int);
void rotate(void);

vector<vector<int>> notebook; // 1-based
vector<vector<int>> sticker(10, vector<int>(10)); // 0-based
int n, m, k; // notebook height & width, n_sticker
int r, c;    // sticker height & width

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    notebook=vector<vector<int>>(n+1,vector<int>(m+1)); // 1-based
    while (k--) {
        cin>>r>>c;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                cin>>sticker[i][j];
            }
        }
        // clockwise, 0:0, 1:90, 2:180, 3:270
        for (int cw = 0; cw<4; ++cw) {
            bool is_success = false;
            for (int x = 1; !is_success && x<=n-(r-1); ++x) {
                for (int y = 1; y<=m-(c-1); ++y) {
                    if (is_suitable(x,y)) {
                        is_success=true;
                        break;
                    }
                }
            }
            if (is_success) {
                break;
            }
            rotate();
        }
    }

    int res = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            res+=notebook[i][j];
        }
    }
    cout << res;

    return 0;
}

bool is_suitable(int x, int y) 
{
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            if (notebook[x+i][y+j] && sticker[i][j]) {

                return false;
            }            
        }
    }
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            if (sticker[i][j]) {
                notebook[x+i][y+j]=1;
            }
        }
    }

    return true;
}

/*
    90's degree clockwise rotation
    (0 0) (0 1) (0 2)    (3 0) (2 0) (1 0) (0 0) 
    (1 0) (1 1) (1 2) -> (3 1) (2 1) (1 1) (0 1)
    (2 0) (2 1) (2 2)    (3 2) (2 2) (1 2) (0 2)
    (3 0) (3 1) (3 2)

    1. row -> col(in reverse)
    (0 0) ...    (3 0) (2 0) (1 0) (0 0) 
    (1 0) ... ->  ...   ...   ...   ...
    (2 0) ...    
    (3 0) ... 

    2. col -> row
    (0 0) (0 1) (0 2)    (3 0) ...
     ...   ...   ...  -> (3 1) ...
     ...   ...   ...     (3 2) ...
     ...   ...   ... 
    a -> b
    a[i][j] => b[(r-1)-j][i] // 0-based
                             // r: 3-> 0, 1, 2 => r-1
*/
void rotate(void)
{
    vector<vector<int>> tmp(sticker);

    for (int i = 0; i<c; ++i) {
        for (int j = 0; j<r; ++j) {
            sticker[i][j] = tmp[(r-1)-j][i];
        }
    }
    swap(r,c);

    return;
}
