// http://icpc.me/18808
#include <bits/stdc++.h>

using namespace std;

bool is_usable(int, int);
void rotate(void);

int notebook[50][50]; // 0, 1 ~ 40, escape OOB
int sticker[12][12];  // 0, 1 ~ 10, -

int n,m,k; // notebook height & width, n_sticker
int r,c;   // sticker height & width

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    while (k--) {
        cin>>r>>c;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) cin>>sticker[i][j];
        }
        // clockwise, 0, 90, 180, 270
        for (int clockwise = 0; clockwise<4; ++clockwise) {
            bool is_succeed=false;

            for (int x = 0; x<=n-r && !is_succeed; ++x) {
                for (int y = 0; y<=m-c; ++y) {
                    if (is_usable(x,y)) {
                        is_succeed=true;
                        break;
                    }
                }
            }
            if (is_succeed) {
                break;
            }
            rotate();
        }
    }
    int cnt=0;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j)
            cnt += notebook[i][j];            
    }
    cout << cnt;

    return 0;
}

bool is_usable(int x, int y)
{
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            if (notebook[x+i][y+j] && sticker[i][j]) 
                return false;
        }
    }
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            if (sticker[i][j])
                notebook[x+i][y+j] = 1;
        }
    }

    return true;
}
/*
    r:2, c: 5  
     y          x

   x *****     ** y    x' = r - j - 1
     *****     **      y' = i
               **
               **
               **
*/
void rotate(void)
{
    int temp[12][12];

    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) 
            temp[i][j]=sticker[i][j];
    }
    // i -> j, j -> i
    for (int i = 0; i<c; ++i) {
        for (int j = 0; j<r; ++j)
            sticker[i][j] = temp[r-j-1][i];
    }
    swap(r,c);

    return;
}