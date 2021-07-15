// https://www.acmicpc.net/problem/2239
#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
/*
 1 2 3 
 4 5 6 
 7 8 9
*/
bool is_used1[3][3][10]; // subsquare
bool is_used2[9][10]; // row
bool is_used3[9][10]; // col

bool bt(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i<9; ++i) {
        for (int j = 0; j<9; ++j) {
            char c;
            cin>>c;
            arr[i][j]=c-'0';

            // subsquare|row|col, digit
            is_used1[i/3][j/3][arr[i][j]]=true;
            is_used2[i][arr[i][j]]=true;
            is_used3[j][arr[i][j]]=true;
        }
        cin.ignore();
    }
    bt(0,0);
    for (int i = 0; i<9; ++i) {
        for (int j = 0; j<9; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}

bool bt(int i, int j)
{
    while (i<9) {
        while (j<9) {
            if (!arr[i][j]) {
                for (int n = 1; n<=9; ++n) {
                    if (is_used1[i/3][j/3][n]==false
                      && is_used2[i][n]==false
                      && is_used3[j][n]==false) {
                        is_used1[i/3][j/3][n]=true;
                        is_used2[i][n]=true;
                        is_used3[j][n]=true;
                        arr[i][j]=n;
                        if (bt(i,j+1)) {

                            return true;
                        }
                        is_used1[i/3][j/3][n]=false;
                        is_used2[i][n]=false;
                        is_used3[j][n]=false;
                        arr[i][j]=0;
                    }
                }
            }
            if (!arr[i][j]) {

                return false;
            }
            ++j;
        }
        j=0;
        ++i;
    }

    return true;
}