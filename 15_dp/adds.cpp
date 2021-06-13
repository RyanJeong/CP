// http://icpc.me/9095
#include <bits/stdc++.h>

using namespace std;

int d[13]; // 0, 1 ~ 11, OOB

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1, 1 + 1 or 2, 1 + 1 + 1 or 1 + 2 or 2 + 1 or 3
    int t;
    cin>>t;
    d[1] = 1, d[2] = 2, d[3] = 4; 

    for (int i = 4; i<11; ++i) {
        d[i]=d[i-1]+d[i-2]+d[i-3];
    }
    while (t--) {
        int n;
        cin>>n;

        cout << d[n] << '\n';
    }

    return 0;
}