// http://icpc.me/12100
#include <bits/stdc++.h>

using namespace std;

void move(int);
void rotate(void);

int n;
int arr[22][22]; // 0, 1 ~20, OOB
int temp[22][22];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>arr[i][j];
        }
    }
    // { up down left right } x 5 times
    int upper = 4 * 4 * 4 * 4 * 4;
    int n_max = 2;

    for (int n_case = 0; n_case < upper; ++n_case) {
        int dir_info = n_case;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i][j] = arr[i][j];
            }
        }
        for (int trial = 0; trial < 5; ++trial) {
            int dir = dir_info % 4;
            move(dir);
            dir_info /= 4;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                n_max = max(temp[i][j], n_max);
            }
        }
    }
    cout << n_max;

    return 0;
}

void move(int dir)
{
    while (dir--) {
        rotate();
    }
    for (int i = 0; i < n; ++i) {
        int i_buf     = 0;
        int buf[22] = { 0 };

        for (int j = 0; j < n; ++j) {
            if (!temp[i][j]) {
                continue;
            }
            if (!buf[i_buf]) {
                buf[i_buf] = temp[i][j];
            } else if (buf[i_buf] == temp[i][j]) {
                buf[i_buf++] *= 2;
            } else {
                buf[++i_buf] = temp[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            temp[i][j] = buf[j];
        }
    }

    return;
}

void rotate(void)
{
    int buf[22][22];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            buf[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = buf[n-j-1][i];
        }
    }
    // swap(r, c);

    return;
}
