#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3] = {1,2,3};

    do {
        for (int i = 0; i<3; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a,a+3));
    /*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    */
    int b[4] = {0,0,1,1};
    do {
        for (int i = 0; i<4; ++i) {
            if (!b[i]) {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    } while (next_permutation(b,b+4));
    /*
    1 2
    1 3
    1 4
    2 3
    2 4
    3 4
    */

    return 0;
}
