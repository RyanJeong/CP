#include <bits/stdc++.h>

using namespace std;

void rotate(int& r, int& c);

vector<vector<int>> arr(100,vector<int>(100)); // 0-based

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            arr[i][j]=i*j+i+j;
        }
    }
    // before
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            cout.width(3);
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    rotate(r,c);
    // after
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            cout.width(3);
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    /*
    > 3 4

    0   1   2   3 
    1   3   5   7 
    2   5   8  11 

    2   1   0 
    5   3   1 
    8   5   2 
    11   7   3
    */

    return 0;
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
void rotate(int& r, int& c)
{
    vector<vector<int>> tmp(arr);

    for (int i = 0; i<c; ++i) {
        for (int j = 0; j<r; ++j) {
            arr[i][j] = tmp[(r-1)-j][i];
        }
    }
    swap(r,c);

    return;
}
